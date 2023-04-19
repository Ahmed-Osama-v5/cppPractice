cmake_minimum_required(VERSION 3.22)

set(TARGET "unitTest")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${TARGET})

include_directories(BEFORE
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(AFTER
    ${CMAKE_SOURCE_DIR}
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
    gcov
)

set(COVERAGE_COMPILE_FLAGS "-Wall -pg -fprofile-arcs -ftest-coverage") # Flags for coverage
set(COVERAGE_LINK_FLAGS "-lgcov --coverage") # Wrappers for GCDA extraction
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COVERAGE_COMPILE_FLAGS}") # append flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILE_FLAGS}") # append flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}") # append flags
