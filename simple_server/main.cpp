#include "sv.hpp"
#include "pretreatment.hpp"

int main(int argc, char const *argv[])
{
    Preconfig pc("server.toml");

    asio::io_context io;
    asio::ip::tcp::endpoint ep(asio::ip::make_address(*pc.ip),
                               *pc.port);
    Server hs(io, ep);
    hs.Start();
    io.run();
    return 0;
}
