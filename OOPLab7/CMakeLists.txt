cmake_minimum_required(VERSION 3.11.1)
project(gtest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab7 main.cpp src/NPC.cpp src/Pegas.cpp src/Knight.cpp src/Dragon.cpp src/Factory.cpp src/Observers.cpp src/DataMethods.cpp src/FightManager.cpp)