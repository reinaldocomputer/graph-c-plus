cmake_minimum_required(VERSION 3.0)
project(graph-c-plus VERSION 0.1.0 LANGUAGES CXX)
set(PROJECT_DIR graph-c-plus)
set(EXECUTABLE_OUTPUT_PATH ../../bin)

# Headers
include_directories(include)

# Sources
add_subdirectory(src)

