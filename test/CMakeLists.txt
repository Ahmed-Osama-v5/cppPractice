cmake_minimum_required(VERSION 3.22)

set(TARGET "unitTest")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${TARGET})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}
                    ${GTEST_INCLUDE_DIRS})

set(TEST_SOURCES    mainTest.cpp
                    ${CMAKE_SOURCE_DIR}/calc.cpp
                    ${CMAKE_SOURCE_DIR}/exampleClass.cpp
                    ${CMAKE_SOURCE_DIR}/Student.cpp
                    calcTest.cpp
                    exampleClassTest.cpp)


add_executable(${TARGET} ${TEST_SOURCES})

target_link_libraries(${TARGET}
    PRIVATE
    pthread
    gtest
    gmock
    gtest_main
)