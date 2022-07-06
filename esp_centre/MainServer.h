#ifndef MAINSERVER_H
#define MAINSERVER_H

#include "asio.hpp"

// 处理 socket 中传输的数据
class Connection : public std::enable_shared_from_this<Connection>
{
private:
    asio::ip::tcp::socket socket_;
    char buff_[1024];

public:
    Connection(asio::io_context &io) : socket_(io) {}

    asio::ip::tcp::socket &GetSocket();

    void DataHandle();
};

class Server
{
private:
    asio::io_context &io_;
    asio::ip::tcp::acceptor acceptor_;

public:
    Server(asio::io_context &io, asio::ip::tcp::endpoint ep) : io_(io), acceptor_(io, ep) {}
    void LoopAccept();
};

#endif