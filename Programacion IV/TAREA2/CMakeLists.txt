cmake_minimum_required(VERSION 3.23)
project(TAREA2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TAREA2
        circular.h
        double.h
        forward.h
        list.h
        main.cpp
        node.h
        tester.h)
