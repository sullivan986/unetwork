#include "MainServer.h"

int main()
{
    asio::io_context io;
    asio::ip::tcp::endpoint ep(asio::ip::make_address("0.0.0.0"), 8080);
    Server sv(io, ep);
    sv.LoopAccept();
    io.run();
}
