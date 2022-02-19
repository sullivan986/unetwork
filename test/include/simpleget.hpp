#ifndef SIMPLEGET_HPP
#define SIMPLEGET_HPP

#include <functional>
#include <memory>
#include <string_view>
#include <string>
#include <regex>

#include "asio.hpp"

class simpleclient
{
private:
    using ahc_callback = std::function<void(std::shared_ptr<simpleclient>)>;
    enum HCStatus
    {
        INIT,
        RESOLVING,
        CONNECTING,
        SENDING_REQUEST,
        RECEIVING_RESPONSE,
        FINISHED
    };

    // callback of resolve
    void ResolveCallback(const asio::error_code &err,
                         const asio::ip::tcp::resolver::results_type &endpoints);
    // callback of connect
    void ConnectCallback(const asio::error_code &err);
    // callback of sending request
    void SendRequestCallback(const asio::error_code &err);
    // got the first line of server response, example:
    void ServerResponseCallback(const asio::error_code &err,
                                std::size_t bytes_transferred);

    std::string_view protocol_; // http or https
    std::string_view host_;     // such as www.qq.com, 129.168.0.1
    std::string_view path_;     // url path, such as /, /index.html

    HCStatus status_;
    asio::io_context &io_context_;
    asio::ip::tcp::resolver resolver_;
    asio::ip::tcp::socket socket_;
    std::string_view url_;
    std::vector<std::pair<std::string, std::string>> request_headers_;
    std::string request_;
    std::vector<std::pair<std::string, std::string>> response_headers_;
    std::string response_;
    ahc_callback finish_callback_;
    std::string err_;

public:
    simpleclient(asio::io_context &io_context, std::string_view url) : status_(INIT), io_context_(io_context), resolver_(io_context),
                                                                       socket_(io_context), url_(url) {}
    ~simpleclient();

    void Start(ahc_callback cb)
    {
        finish_callback_ = cb;
        // parse url
        std::regex re("(https?)://([^/]+)((/.*)*)");
        std::smatch sm;
        if (!std::regex_match(url_, sm, re))
        {
            err_ = "invalid url";
            finish_callback_(std::shared_from_this());
            return;
        }

        protocol_ = sm[1];
        host_ = sm[2];
        path_ = sm[3].str() == "" ? "/" : sm[3].str();

        // std::cout<<"parsed, protocol="<<protocol_<<", host="<<host_<<", path="<<path_<<"\n";

        // asynchronous resolve host name to ip address
        resolver_.async_resolve(host_, protocol_,
                                std::bind(&AsyncHttpClient::ResolveCallback, this, _1, _2));
    }

    int Result(); // 0 for ok, otherwise failed
    std::string Err()
    {
        return err_;
    } // if Result returns non zero, Err return detail message
};

#endif
