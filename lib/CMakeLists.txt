cmake_minimum_required(VERSION 3.0)
project(godll)

set(CMAKE_CXX_STANDARD 14)

add_library(godll SHARED library.cpp)

add_executable(test test.cpp test.h)
