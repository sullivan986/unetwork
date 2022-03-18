add_executable(simple_server
    main.cpp
    sv.hpp
)

find_package(asio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(simple_server PRIVATE Threads::Threads)
target_link_libraries(simple_server PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(simple_server PRIVATE asio asio::asio)