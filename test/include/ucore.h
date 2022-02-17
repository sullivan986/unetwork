#ifndef UCORE_UCORE_h
#define UCORE_UCORE_h

#include "asio.hpp"
#include "fmt/core.h"

class HttpServer : public std::enable_shared_from_this<HttpServer>
{
public:
    HttpServer(asio::io_context &io) : socket_(io)
    {
    }

private:
    asio::ip::tcp::socket socket_;
};

#endif