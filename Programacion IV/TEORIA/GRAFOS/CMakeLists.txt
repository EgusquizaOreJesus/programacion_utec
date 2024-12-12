cmake_minimum_required(VERSION 3.25)
project(GRAFOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(GRAFOS main.cpp)
add_executable(DSU DSU.cpp)
add_executable(busqueda busqueda_grafos.cpp)
add_executable(disperso grafo_disperso.cpp)
add_executable(b backtracking.cpp solucion.h)