cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(multithreading$ VERSION 1.0)

# source files, *.cpp
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(test2 test2.cpp ${SRC_FILES})
# header files
target_include_directories(test2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

TARGET_LINK_LIBRARIES(test2 pthread)