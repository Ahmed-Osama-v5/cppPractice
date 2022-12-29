cmake_minimum_required(VERSION 2.8)

set(TARGET "main")

project(${TARGET})

set(SOURCES main.cpp
            exampleClass.cpp
            Student.cpp)

add_executable(${TARGET} ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(BUILD_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
