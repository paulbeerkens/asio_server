cmake_minimum_required(VERSION 3.8)
project(asio_server)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp )
add_executable(asio_server ${SOURCE_FILES})

target_link_libraries(asio_server libAsioGenericServer)

add_subdirectory(AsioGenericServer)