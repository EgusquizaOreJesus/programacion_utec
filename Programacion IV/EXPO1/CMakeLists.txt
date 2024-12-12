cmake_minimum_required(VERSION 3.23)
project(EXPO1)

set(CMAKE_CXX_STANDARD 20)

add_executable(EXPO1 main.cpp)
add_executable(sorting sorting_benchmark.cpp SortingAlgoritmos.h)