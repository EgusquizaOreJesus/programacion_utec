cmake_minimum_required(VERSION 3.25)
project(GRAFOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(GRAFOS main.cpp)
add_executable(kruskal kruskal.cpp)
add_executable(borrador borrador.cpp)