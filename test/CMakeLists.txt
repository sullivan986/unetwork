aux_source_directory(src SRC)

include_directories(include)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(test
    ${SRC}
)

find_package(fmt CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
target_link_libraries(test PRIVATE fmt::fmt)
target_link_libraries(test PRIVATE asio asio::asio)
target_link_libraries(test PRIVATE tomlplusplus::tomlplusplus)
