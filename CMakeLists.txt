cmake_minimum_required(VERSION 3.31)
project(aLogger)

set(CMAKE_CXX_STANDARD 20)

add_executable(aLogger main.cpp
        headers/logging.h)
