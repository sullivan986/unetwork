#include "asio.hpp"
#include "spdlog/spdlog.h"

class Connection : public std::enable_shared_from_this<Connection>
{
public:
    Connection(asio::io_context &io) : socket_(io) {}

    void Start()
    {
        auto p = shared_from_this();
        asio::async_read_until(socket_, asio::dynamic_buffer(request_),
                               "\r\n\r\n",
                               [p, this](const asio::error_code &err, size_t len)
                               {
                                   if (err)
                                   {
                                       spdlog::error(err.message());
                                       return;
                                   }
                                   std::string first_line = request_.substr(0, request_.find("\r\n")); // should be like: GET / HTTP/1.0
                                   spdlog::info(first_line);
                                   // process with request
                                   // ...

                                   char str[] = "HTTP/1.0 200 OK\r\n\r\n"
                                                "<html>hello from http server</html>";
                                   asio::async_write(socket_, asio::buffer(str), [p, this](const asio::error_code &err, size_t len)
                                                     { socket_.close(); });
                               });
    }

    asio::ip::tcp::socket &Socket()
    {
        return socket_;
    }

private:
    asio::ip::tcp::socket socket_;
    std::string request_;
};

class Server
{
public:
    Server(asio::io_context &io, asio::ip::tcp::endpoint ep) : io_(io), acceptor_(io, ep)
    {
    }

    void Start()
    {
        auto p = std::make_shared<Connection>(io_);
        acceptor_.async_accept(p->Socket(),
                               [p, this](const asio::error_code &err)
                               {
                                   if (err)
                                   {
                                       spdlog::error(err.message());
                                       return;
                                   }
                                   p->Start();
                                   Start();
                               });
    }

private:
    asio::io_context &io_;
    asio::ip::tcp::acceptor acceptor_;
};