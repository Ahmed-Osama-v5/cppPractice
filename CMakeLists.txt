cmake_minimum_required(VERSION 2.8)

set(TARGET "cppPractice")

project(${TARGET})

set(SOURCES "main.cpp"
            "Strategy_Pattern_Example/Batta.cpp")

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Strategy_Pattern_Example")

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tcp-server)
