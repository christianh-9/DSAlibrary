cmake_minimum_required(VERSION 3.30)
project(firstProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(firstProject src/main.cpp
        src/LinkedList.cpp
        include/LinkedList.h
        src/Stack.cpp
        include/Stack.h
        src/Queue.cpp
        include/Queue.h
        src/Graph.cpp
        include/Graph.h
        src/BinaryTree.cpp
        include/BinaryTree.h
        src/Menu.cpp
        include/Menu.h
        src/HashTable.cpp
        include/HashTable.h)
