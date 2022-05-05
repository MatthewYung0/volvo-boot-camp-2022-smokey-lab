cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CanReadWrite VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(CanReadWrite main.cpp ${SRC_FILES})

target_include_directories(CanReadWrite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Curses REQUIRED)
target_include_directories(CanReadWrite PUBLIC ${CURSES_INCLUDE_DIRS})


target_link_libraries(CanReadWrite PUBLIC SocketCanlib)

target_link_libraries(CanReadWrite PUBLIC ${CURSES_LIBRARIES})