# https://codevion.github.io/#!cpp/cmake.md

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(canio VERSION 1.0)


# source files, *.cpp
file(GLOB_RECURSE SRC_FILES src/*.cpp)


# Executable
add_executable(canio main.cpp ${SRC_FILES})

# Libraries
TARGET_LINK_LIBRARIES(canio curses)

# header files
target_include_directories(canio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)