cmake_minimum_required(VERSION 2.8)

set(TARGET "app")

project(${TARGET})

set(SOURCES "main.cpp"
            "eventManager/EventManager.cpp")

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/eventManager")
