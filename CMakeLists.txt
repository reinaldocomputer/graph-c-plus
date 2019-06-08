cmake_minimum_required(VERSION 3.0)
project(graph-c-plus VERSION 0.1.0 LANGUAGES CXX)
set(EXECUTABLE_OUTPUT_PATH ../../bin)

# Directories
add_subdirectory(include)
add_subdirectory(src)

# linking
include_directories(include)
include_directories(src)


