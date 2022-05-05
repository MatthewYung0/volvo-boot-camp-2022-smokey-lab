cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(InputHandler VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(InputHandler main.cpp ${SRC_FILES})

target_include_directories(InputHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Curses REQUIRED)
target_include_directories(InputHandler PUBLIC ${CURSES_INCLUDE_DIRS})


target_link_libraries(InputHandler PUBLIC SocketCanlib)

target_link_libraries(InputHandler PUBLIC ${CURSES_LIBRARIES})