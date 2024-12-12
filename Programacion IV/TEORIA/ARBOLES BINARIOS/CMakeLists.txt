cmake_minimum_required(VERSION 3.23)
project(ARBOLES_BINARIOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(ARBOLES_BINARIOS main.cpp)
add_executable(ARBOLAVL ARBOL_AVL.cpp)
add_executable(heap HEAPS.cpp)
add_executable(arbolB ARBOL_B.cpp)
add_executable(arbolB+ arbolB+.cpp)