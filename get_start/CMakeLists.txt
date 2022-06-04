include_directories(
    .
)

aux_source_directory(. CPPSRC)

add_executable(get_start
    ${CPPSRC}
)

find_package(asio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)    

target_link_libraries(get_start PRIVATE Threads::Threads)
target_link_libraries(get_start PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(get_start PRIVATE asio asio::asio)
