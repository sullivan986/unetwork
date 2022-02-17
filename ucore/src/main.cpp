#include <vector>

#include "asio.hpp"
#include "fmt/core.h"

int main(int argc, char const *argv[])
{
    asio::error_code er;

    asio::io_context ioc;

    asio::ip::tcp::endpoint ep(asio::ip::make_address("192.168.0.113", er), 8080);

    asio::ip::tcp::socket _socket(ioc);

    _socket.connect(ep, er);

    if (!er)
    {
        fmt::print("Connecting successful");
    }
}
