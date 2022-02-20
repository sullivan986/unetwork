aux_source_directory(src SRC)

include_directories(include)

aux_source_directory(src SRC)

include_directories(include)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(simple_server
    ${SRC}
)

find_package(fmt CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
target_link_libraries(simple_server PRIVATE fmt::fmt)
target_link_libraries(simple_server PRIVATE asio asio::asio)
target_link_libraries(simple_server PRIVATE tomlplusplus::tomlplusplus)