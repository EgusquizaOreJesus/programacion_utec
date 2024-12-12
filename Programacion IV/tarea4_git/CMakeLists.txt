cmake_minimum_required(VERSION 3.23)
project(tarea4_git)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tarea4_git
        bst.h
        iterator.h
        main.cpp
        node.h
        tester.h)
