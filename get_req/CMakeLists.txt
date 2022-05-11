add_executable(get_req
    main.cpp
)

find_package(asio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)    

target_link_libraries(get_req PRIVATE Threads::Threads)
target_link_libraries(get_req PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(get_req PRIVATE asio asio::asio)
