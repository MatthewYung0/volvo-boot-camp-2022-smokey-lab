cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(libuserinputcheck VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

target_include_directories(libcanio PUBLIC libuserinputcheck)