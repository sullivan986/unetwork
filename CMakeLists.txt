cmake_minimum_required(VERSION 3.20)

project(
    unetwork
    VERSION 0.0.1
    DESCRIPTION "A c++ web server with Asio"
    HOMEPAGE_URL "https://github.com/sullivan986/unetwork"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(simple_server)