cmake_minimum_required(VERSION 3.30)
project(AdventOfCode C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Put *all* outputs into a build subfolder inside cmake-build-debug
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Example executables
add_executable(advent01_1 01/advent01_1.c)
add_executable(advent01_2 01/advent01_2.c)
#add_executable(advent02 02/advent02_1.c) Done in python
add_executable(advent03_1 03/advent03_1.c)
add_executable(advent03_2 03/advent03_2.c)