add_executable(simple_server
    main.cpp
    pretreatment.hpp
    sv.hpp
)

find_package(asio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)    
find_package(tomlplusplus CONFIG REQUIRED)

target_link_libraries(simple_server PRIVATE tomlplusplus::tomlplusplus)
target_link_libraries(simple_server PRIVATE Threads::Threads)
target_link_libraries(simple_server PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(simple_server PRIVATE asio asio::asio)

configure_file(server.toml ${PROJECT_BINARY_DIR}/simple_server COPYONLY)