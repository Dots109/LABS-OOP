cmake_minimum_required(VERSION 3.22.1)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 main.cpp)

enable_testing()

add_executable(tests test.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)