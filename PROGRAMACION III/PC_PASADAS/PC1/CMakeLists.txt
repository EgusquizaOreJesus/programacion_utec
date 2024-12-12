cmake_minimum_required(VERSION 3.23)
project(PC1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PC1 main.cpp)
add_executable(exercise1 p1.cpp Polinomio.cpp Polinomio.h)
add_executable(exercise2 p2.cpp)