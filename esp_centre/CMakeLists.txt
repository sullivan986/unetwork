include_directories(.)
aux_source_directory(. SRC)

add_executable(esp_centre
    ${SRC}
)

find_package(asio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)  

target_link_libraries(esp_centre PRIVATE Threads::Threads)
target_link_libraries(esp_centre PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
target_link_libraries(esp_centre PRIVATE asio asio::asio)