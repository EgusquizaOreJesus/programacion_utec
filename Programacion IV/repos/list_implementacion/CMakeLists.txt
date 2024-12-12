cmake_minimum_required(VERSION 3.25)
project(list_implementacion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(list_implementacion
        circular.h
        double.h
        forward.h
        list.h
        main.cpp
        tester.h)
