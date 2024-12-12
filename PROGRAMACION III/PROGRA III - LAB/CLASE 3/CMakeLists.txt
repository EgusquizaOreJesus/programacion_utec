cmake_minimum_required(VERSION 3.23)
project(CLASE_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLASE_3 main.cpp)
add_executable(ejercicio1 Ejercicios1.cpp function1.cpp function1.h Numeros.cpp Numeros.h)
add_executable(exercise3 ejercicio3.cpp)
add_executable(exercise4 ejercicio4.cpp number.cpp number.h)
add_executable(borrador borrador.cpp)