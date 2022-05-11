cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(input_handler VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(input_handler main.cpp ${SRC_FILES})

target_include_directories(input_handler PUBLIC include)

target_include_directories(input_handler PUBLIC ../../common/libuserinputcheck)

find_package(Curses REQUIRED)

target_link_libraries(input_handler PUBLIC ${CURSES_LIBRARIES})

target_link_libraries(input_handler PUBLIC libcanio)

target_link_libraries(input_handler PUBLIC socketcanexternallib)

