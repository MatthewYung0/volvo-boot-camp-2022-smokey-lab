# https://codevion.github.io/#!cpp/cmake.md

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(msg_handler VERSION 1.0)

# source files, *.cpp
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Executable
add_executable(msg_handler main.cpp ${SRC_FILES})

# header files
target_include_directories(msg_handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)