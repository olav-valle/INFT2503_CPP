cmake_minimum_required(VERSION 3.1)

project(pointer_addition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(pointer_addition main.cpp)
