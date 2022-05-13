cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

project(emulator VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(emulator main.cpp ${SRC_FILES})

target_include_directories(emulator PUBLIC include)

target_include_directories(emulator PUBLIC ../../common)

target_link_libraries(emulator PUBLIC libcanio)

target_include_directories(emulator PUBLIC libuserinputcheck)

find_package(Threads REQUIRED)

target_link_libraries(emulator PUBLIC Threads::Threads)