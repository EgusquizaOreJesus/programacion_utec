cmake_minimum_required(VERSION 3.23)
project(trie_bocchi_the_trie)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(trie_bocchi_the_trie
        main.cpp
        patriciatrie.h
        simpletrie.h
        tester.h
        trie.h)

add_executable(trie_bocchi_the_trie_tiempo Pruebas_Temporales.cpp patriciatrie.h simpletrie.h trie.h)
