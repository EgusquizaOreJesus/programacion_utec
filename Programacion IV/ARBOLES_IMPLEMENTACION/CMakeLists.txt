#cmake_minimum_required(VERSION 3.25)
#project(examenes_parciales)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(examenes_parciales
#        examen1/examen1.cpp)

cmake_minimum_required(VERSION 3.25)
project(ARBOLES_IMPLEMENTACION)

set(CMAKE_CXX_STANDARD 14)

# Agrega todos los archivos fuente en la carpeta src


# Genera el ejecutable con todos los archivos fuente
add_executable(arbol src/sss.cpp)
add_executable(ss src/borrador.cpp)
add_executable(btree src/B_TREE.cpp)
add_executable(borrador2 src/borrador2.cpp)
add_executable(trie src/trie.cpp)
add_executable(borrador3 src/borrador3.cpp)
add_executable(avl src/AVL_TREE.cpp)
add_executable(flody src/flody.cpp)
add_executable(btree2 B_tree2.cpp)