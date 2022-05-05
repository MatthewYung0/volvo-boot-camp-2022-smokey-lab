cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(libemulator VERSION 1.0)

add_library(libemulator STATIC src/Emulator.cpp)

target_include_directories(libemulator PUBLIC include)