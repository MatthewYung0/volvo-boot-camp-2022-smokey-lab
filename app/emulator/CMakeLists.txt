cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy
-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
-Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls
-Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5
-Wswitch-default -Wundef -Werror -Wno-unused)

project(emulator VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(emulator main.cpp ${SRC_FILES})

target_include_directories(emulator PUBLIC include)

target_include_directories(emulator PUBLIC ../../common)

target_link_libraries(emulator PUBLIC libcanio)

find_package(Threads REQUIRED)

target_link_libraries(emulator PUBLIC Threads::Threads)