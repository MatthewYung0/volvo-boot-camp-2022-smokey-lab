cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SocketCAN VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/src/socketcan_cpp.cpp)

add_library(socketcanexternallib STATIC src/socketcan_cpp.cpp)

target_include_directories(socketcanexternallib PUBLIC include)