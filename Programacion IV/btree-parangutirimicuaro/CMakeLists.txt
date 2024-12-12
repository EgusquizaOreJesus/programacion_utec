cmake_minimum_required(VERSION 3.25)
project(btree_parangutirimicuaro)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(btree_parangutirimicuaro
        btree.h
        main.cpp
        node.h
        tester.h)
