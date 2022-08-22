cmake_minimum_required(VERSION 3.1)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(hello main.cpp)
add_executable(hello2 hello2.cpp)
