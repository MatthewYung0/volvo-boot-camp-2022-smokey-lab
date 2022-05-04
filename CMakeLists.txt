# https://codevion.github.io/#!cpp/cmake.md

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(eg_simulator VERSION 1.0)

add_subdirectory(lib/libcanreadwrite)
add_subdirectory(lib/libinputhandler)