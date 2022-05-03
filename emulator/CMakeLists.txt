cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(engine VERSION 1.0)

# source files, *.cpp
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Executable
add_executable(engine main.cpp ${SRC_FILES})

# header files
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)