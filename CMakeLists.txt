cmake_minimum_required(VERSION 2.8)

set(TARGET "main")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${TARGET})

set(SOURCES main.cpp
            Strategy_Pattern_Example/Batta.cpp)


add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Strategy_Pattern_Example")


# target_link_libraries(${TARGET}
#             PRIVATE
#             pthread
#             gtest
#             gmock
#             gtest_main
# )

if(BUILD_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
