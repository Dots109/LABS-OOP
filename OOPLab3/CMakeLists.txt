cmake_minimum_required(VERSION 3.11.1)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3 main.cpp src/figure.cpp src/square.cpp src/triangle.cpp src/octagon.cpp src/arrayFig.cpp)

enable_testing()

add_executable(tests test/test.cpp src/figure.cpp src/square.cpp src/triangle.cpp src/octagon.cpp src/arrayFig.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)