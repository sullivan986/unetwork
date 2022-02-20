aux_source_directory(src SRC)

include_directories(include)
include_directories(module)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(ucore
    ${SRC}
)

find_package(fmt CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
target_link_libraries(ucore PRIVATE fmt::fmt)
target_link_libraries(ucore PRIVATE asio asio::asio)
target_link_libraries(ucore PRIVATE tomlplusplus::tomlplusplus)

configure_file(server.toml ${PROJECT_BINARY_DIR}/ucore COPYONLY)