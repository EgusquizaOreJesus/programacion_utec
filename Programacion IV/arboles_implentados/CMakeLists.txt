cmake_minimum_required(VERSION 3.25)
project(arboles_implentados)

set(CMAKE_CXX_STANDARD 20)
# Agrega todos los archivos fuente en la carpeta src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Genera el ejecutable con todos los archivos fuente
add_executable(arboles_implentados2 ${SOURCES})
