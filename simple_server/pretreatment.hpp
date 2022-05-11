#ifndef PRETREATMENT_HPP
#define PRETREATMENT_HPP

#include "toml++/toml.h"

class Preconfig
{
public:
    Preconfig(std::string_view confpath)
    {
        _tb = toml::parse_file(confpath);
        port = *_tb["server"]["port"].value<int32_t>();
        ip = *_tb["server"]["ip"].value<std::string_view>();
    }

    Preconfig() {}

    constexpr void ParesFile(std::string_view confpath)
    {
        _tb = toml::parse_file(confpath);
        port = *_tb["server"]["port"].value<int32_t>();
        ip = *_tb["server"]["ip"].value<std::string_view>();
    }

    int32_t port;
    std::string_view ip;

private:
    toml::table _tb;
};

#endif