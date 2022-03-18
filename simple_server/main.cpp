#include "sv.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        spdlog::error("usage: httpsvr ip port");
        return 0;
    }

    return 0;
}
