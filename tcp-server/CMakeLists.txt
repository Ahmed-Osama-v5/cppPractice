cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(tcp-server)

set(SERVER_SOURCES "tcp_server.cpp")

add_executable(tcp-server ${SERVER_SOURCES})

target_link_libraries(tcp-server
    PRIVATE
        pthread
        ${Boost_LIBRARIES}
)