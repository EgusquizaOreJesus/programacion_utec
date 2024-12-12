cmake_minimum_required(VERSION 3.23)
project(CLASE_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLASE_3 main.cpp)
add_executable(ejemplo example.cpp aritmetica.cpp aritmetica.h)
add_executable(Singleton example_Singleton.cpp)
add_executable(Singleton2 example2_Singleton.cpp)