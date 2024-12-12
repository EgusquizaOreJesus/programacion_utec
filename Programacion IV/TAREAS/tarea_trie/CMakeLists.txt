cmake_minimum_required(VERSION 3.25)
project(tarea_trie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tarea_trie
        main.cpp
        patriciatrie.h
        simpletrie.h
        tester.h
        trie.h)
