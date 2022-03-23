#ifndef PRETREATMENT_HPP
#define PRETREATMENT_HPP

#include "toml++/toml.h"

class Preconfig
{
public:
    Preconfig(const std::string_view &confpath)
    {
        _tb = toml::parse_file(confpath);
        port = _tb["server"]["port"].value<int32_t>();
        ip = _tb["server"]["ip"].value<std::string_view>();
    }

    std::optional<int32_t> port;
    std::optional<std::string_view> ip;

private:
    toml::table _tb;
};

#endif