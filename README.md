# Graph C++ (Work in Progress)
## An easy way for using graphs on your project.

### Introduction

It's available in this project a Graph Lab and a Graph Library.

### How to add the Graph Library on your project?

If you wanna use this library on your project then you have to copy src/Graph.cpp and include/Graph.h files and include the Graph.h inside your source code.

### How to use the Graph Lab?
It's easy, but you have to follow some instructions.
* Clone our repository.
* Get in the main folder.
```sh
$ cd build
$ make
```
If everything is okay then you already compiled the main file and now you can use it.
Go back to the main folder
```sh
$ cd ..
```
Now you can run the binary file using -i flag and choosing an input file.
```sh
$ bin/main -i your_archive.txt
```
Your text file need be in the correct format for running correctly.
You can also run some prepared samples.
```sh
$ bin/main -i tests/*.txt
```

### Features
* Vertices Degrees
* BFS - BFS Breadth-First Search
* DFS - Depth-First Search
* Detect Cycle
* Topological Sort
* Strongly Connected Components

## Contact

You can contact me by my e-mail:
rfsaraujobr@gmail.com

Best regards,

Reinaldo Araujo
