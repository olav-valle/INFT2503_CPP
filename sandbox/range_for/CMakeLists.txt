cmake_minimum_required(VERSION 3.1)

project(range_for)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(range_for main.cpp)
