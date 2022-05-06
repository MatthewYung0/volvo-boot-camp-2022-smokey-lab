cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(libuserinput VERSION 1.0)

add_library(libuserinput STATIC src/checkinput.cpp)

target_link_libraries(libuserinput PUBLIC socketcanexternallib)

target_include_directories(libuserinput PUBLIC include)