#include <vector>
#include <utility>

#include "asio.hpp"
#include "fmt/core.h"
#include "toml++/toml.h"

int main(int argc, char const *argv[])
{
    toml::table toml_tb = toml::parse_file("server.toml");
}
