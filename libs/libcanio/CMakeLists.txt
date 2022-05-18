cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy
-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
-Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls
-Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5
-Wswitch-default -Wundef -Werror -Wno-unused)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(libcanio VERSION 1.0)

add_library(libcanio STATIC src/socketcansetup.cpp)

target_link_libraries(libcanio PUBLIC socketcanexternallib)

target_include_directories(libcanio PUBLIC include)
