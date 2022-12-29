cmake_minimum_required(VERSION 2.8)

set(TARGET "unitTest")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${TARGET})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SOURCES    mainTest.cpp
                    ${CMAKE_SOURCE_DIR}/calc.cpp
                    ${CMAKE_SOURCE_DIR}/exampleClass.cpp
                    ${CMAKE_SOURCE_DIR}/Student.cpp
                    calcTest.cpp
                    exampleClassTest.cpp)

include_directories(${CMAKE_SOURCE_DIR})


add_executable(${TARGET} ${TEST_SOURCES})

target_link_libraries(${TARGET}
    PRIVATE
    pthread
    gtest
    gmock
    gtest_main
)