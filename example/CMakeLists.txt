cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(can_read_example VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(can_read can_read.cpp ${SRC_FILES})

target_include_directories(can_read_example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Curses REQUIRED)
target_include_directories(can_read_example PUBLIC ${CURSES_INCLUDE_DIRS})


target_link_libraries(can_read_example PUBLIC SocketCanlib)

target_link_libraries(can_read_example PUBLIC ${CURSES_LIBRARIES})