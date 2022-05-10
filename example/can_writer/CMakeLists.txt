cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(can_writer VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(can_writer can_write.cpp ${SRC_FILES})

target_link_libraries(can_writer PUBLIC libcanio)

target_link_libraries(can_writer PUBLIC libcanio)

target_link_libraries(can_writer PUBLIC libuserinput)