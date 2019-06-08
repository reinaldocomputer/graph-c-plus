add_executable(main  main.cpp)

add_library(Graph STATIC Graph.cpp)
target_link_libraries(
    Graph
)

include_directories(./)
include_directories(Graph)

