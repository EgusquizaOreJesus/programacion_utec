cmake_minimum_required(VERSION 3.23)
project(CODEROOM2)

set(CMAKE_CXX_STANDARD 20)

add_executable(CODEROOM2 main.cpp)
add_executable(forward forward_list.cpp)
add_executable(implementacion implementar_hash.cpp forward_list.h chainhash.h)