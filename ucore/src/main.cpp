#include "asio.hpp"
#include "fmt/color.h"

int main(int argc, char const *argv[])
{

    asio::error_code er;

    asio::io_context ioc;

    asio::ip::tcp::endpoint ep(asio::ip::make_address("0.0.0.0", er), 8080);

    asio::ip::tcp::socket _socket(ioc);

    fmt::print(fmt::emphasis::blink, "program ending!\r123\n");
}
