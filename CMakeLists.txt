# cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# project(bookshop VERSION 1.0)

# add_library(mylib STATIC src/Welcomeback.cpp)
# target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_executable(bookshop main.cpp)
# target_link_libraries(bookshop PUBLIC mylib)

cmake_minimum_required(VERSION 2.4)

project(bookshop)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(bookshopapp main.cpp book_functions.cpp Book.cpp)