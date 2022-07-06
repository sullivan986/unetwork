#include <functional>
#include "asio.hpp"
#include "spdlog/spdlog.h"

#include "gst.h"

class Timer
{
private:
    asio::steady_timer timer_;
    asio::io_context &io_;
    int time_sec;

public:
    Timer(asio::io_context &io) : io_(io), timer_(io_)
    {
        timer_.expires_after(asio::chrono::seconds(1));
        timer_.async_wait(
            [this](const asio::error_code &)
            {
                spdlog::info("Hi~");
            });
    }
    ~Timer();
};

void print(asio::steady_timer &timer, int &count)
{
    if (count < 10)
    {
        spdlog::info("count: {}", count++);
        timer.expires_after(asio::chrono::seconds(1));
        timer.async_wait([&](const asio::error_code &c)
                         { print(timer, count); });
    }
}

void basic_timer()
{
    asio::io_context ioc;
    spdlog::info("start");

    asio::steady_timer timer1(ioc, std::chrono::seconds(1));
    timer1.async_wait([](const asio::error_code &ec)
                      { spdlog::info(ec.message()); });

    asio::steady_timer timer2(ioc);
    timer2.expires_after(std::chrono::milliseconds(100));
    timer2.async_wait([&timer1](const std::error_code &)
                      {
        timer1.cancel();
        spdlog::info("timer2 timeout\n"); });
    ioc.run();
    spdlog::info("fi");
}