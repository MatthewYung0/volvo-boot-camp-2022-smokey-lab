cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(libcanio VERSION 1.0)

add_library(libcanio STATIC src/canmessage.cpp src/socketcansetup.cpp)

target_link_libraries(libcanio PUBLIC socketcanexternallib)

target_include_directories(libcanio PUBLIC include)

target_include_directories(libcanio PUBLIC ../libuserinputcheck)