cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/src/socketcan_cpp.cpp)

project(SocketCAN VERSION 1.0)

add_library(SocketCanlib STATIC src/socketcan_cpp.cpp)
target_include_directories(SocketCanlib PUBLIC include)