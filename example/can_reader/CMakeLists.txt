cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(can_reader VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(can_reader can_read.cpp ${SRC_FILES})

target_link_libraries(can_reader PUBLIC libcanio)

target_include_directories(can_reader PUBLIC ../app/input_handler/include)