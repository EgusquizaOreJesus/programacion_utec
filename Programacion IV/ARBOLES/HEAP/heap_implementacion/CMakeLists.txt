cmake_minimum_required(VERSION 3.25)
project(heap_implementacion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(heap_implementacion
        heap.h
        main.cpp
        tester.h)
