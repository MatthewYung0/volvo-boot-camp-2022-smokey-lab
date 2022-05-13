cmake_minimum_required(VERSION 3.10)

project(eg_simulator VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(libs)
add_subdirectory(example)
add_subdirectory(app)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/libs/CMakeLists.txt" LOC_PATH)
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/libs/libcanreadwrite/CMakeLists.txt" LOC_PATH)
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/external/socketcan-cpp-master/CMakeLists.txt" LOC_PATH)
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/example/CMakeLists.txt" LOC_PATH)
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/app/CMakeLists.txt" LOC_PATH)
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}app/output_display/CMakeLists.txt" LOC_PATH)