#cmake_minimum_required(VERSION 3.25)
#project(examenes_parciales)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(examenes_parciales
#        examen1/examen1.cpp)

cmake_minimum_required(VERSION 3.25)
project(examenes_parciales)

set(CMAKE_CXX_STANDARD 14)

# Agrega todos los archivos fuente en la carpeta src
file(GLOB_RECURSE SOURCES "examen1/*.cpp")

# Genera el ejecutable con todos los archivos fuente
add_executable(examenes_parciales ${SOURCES})
