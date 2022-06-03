#include <string_view>
#include <iostream>
#include <sstream>
#include "asio.hpp"
#include "spdlog/spdlog.h"

std::string dom = "https://restapi.amap.com/v3/weather/weatherInfo?parameters?city=110101&key=98e7b0591d5c45e6f7b8a6493f6ff5dd";

int main(int argc, char const *argv[])
{
    asio::error_code ec;
    asio::io_context io;

    return 0;
}
