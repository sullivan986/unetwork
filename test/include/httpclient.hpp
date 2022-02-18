#ifndef HTTPCLIENT_HPP
#define HTTPCLIENT_HPP

#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <asio.hpp>

class AsyncHttpClient : public std::enable_shared_from_this<AsyncHttpClient>
{
private:
    /* data */
public:
    AsyncHttpClient(/* args */);
    ~AsyncHttpClient();
};

#endif