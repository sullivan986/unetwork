#include "spdlog/spdlog.h"

#include "MainServer.h"

asio::ip::tcp::socket &Connection::GetSocket()
{
    return socket_;
}

void Connection::DataHandle()
{
    auto p = shared_from_this();

    socket_.async_read_some(asio::buffer(buff_, sizeof(buff_)), [p, this](const asio::error_code &err, size_t len)
                            {
        spdlog::info("recved: {}", buff_);
        socket_.async_write_some(asio::buffer(buff_, sizeof(buff_)), [p, this](const asio::error_code &err, size_t len){
            spdlog::info("send data: {}", buff_);
            bzero(buff_,sizeof(buff_));
            DataHandle();
        }); });
}

void Server::LoopAccept()
{
    auto p = std::make_shared<Connection>(io_);
    acceptor_.async_accept(p->GetSocket(), [p, this](const asio::error_code &ec)
                           {
                                   if (ec)
                                   {
                                       spdlog::warn("Accept error:{}",ec.message());
                                   }else{
                                       spdlog::info("A device connected");
                                   }
                                   p->DataHandle();
                                   LoopAccept(); });
}