cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(emulator VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(emulator emulator.cpp ${SRC_FILES})

find_package(Curses REQUIRED)

target_link_libraries(emulator PUBLIC libemulator)

target_link_libraries(emulator PUBLIC ${CURSES_LIBRARIES})