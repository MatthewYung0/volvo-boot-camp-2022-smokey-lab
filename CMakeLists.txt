cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(input_handler_app VERSION 1.0)
find_package(Curses)

add_library(input_handler_lib SHARED 
                                    src/checkInput.cpp)

target_include_directories(input_handler_lib PUBLIC ${CURSES_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(input_handler_app main.cpp)
target_link_libraries(input_handler_app PUBLIC input_handler_lib)
target_link_libraries(LearnC ${CURSES_LIBRARIES})