#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include "patriciatrie.h"
#include "simpletrie.h"

// Función para generar una palabra aleatoria
std::string generarPalabraAleatoria(int longitud) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(97, 122);  // rango de caracteres 'a'-'z'

    std::string palabra;
    for (int i = 0; i < longitud; ++i) {
        palabra.push_back(static_cast<char>(dis(gen)));
    }
    return palabra;
}

// Función para generar un diccionario con la cantidad de palabras especificada
std::vector<std::string> generarDiccionario(int cantidadPalabras, int longitudPalabra) {
    std::vector<std::string> diccionario;
    diccionario.reserve(cantidadPalabras);
for (int i = 0; i < cantidadPalabras; ++i) {
//        cout<<i<<endl;
        diccionario.push_back(generarPalabraAleatoria(longitudPalabra));
    }
    return diccionario;
}

// Función para realizar las pruebas de búsqueda en el trie normal
void pruebaTrieNormal(const std::vector<std::string>& diccionario, int cantidadBusquedas) {
    // Crear el trie normal y agregar las palabras del diccionario
    TrieSimple trie;
    for (const auto& palabra : diccionario) {
        trie.insert(palabra);
    }

    // Realizar las pruebas de búsqueda y medir los tiempos
    std::vector<double> tiempos;
    for (int i = 0; i < cantidadBusquedas; ++i) {
        std::string palabraBusqueda = generarPalabraAleatoria(int(diccionario[0].size()));

        auto inicio = std::chrono::high_resolution_clock::now();
        trie.search(palabraBusqueda);
        auto fin = std::chrono::high_resolution_clock::now();

        double tiempo = std::chrono::duration<double, std::milli>(fin - inicio).count();
        tiempos.push_back(tiempo);
    }

    // Calcular el tiempo medio
    double tiempoMedio = 0.0;
    for (const auto& tiempo : tiempos) {
        tiempoMedio += tiempo;
    }
    tiempoMedio /= cantidadBusquedas;

    // Guardar el tiempo medio en un archivo
    std::ofstream archivo("normal.txt", ios::app);
    archivo << tiempoMedio << std::endl;
    archivo.close();
}

// Función para realizar las pruebas de búsqueda en el patricia trie
void pruebaPatriciaTrie(const std::vector<std::string>& diccionario, int cantidadBusquedas) {
    // Crear el patricia trie y agregar las palabras del diccionario
    TriePatricia patriciaTrie;
    for (const auto& palabra : diccionario) {
        patriciaTrie.insert(palabra);
    }

    // Realizar las pruebas de búsqueda y medir los tiempos
    std::vector<double> tiempos;
    for (int i = 0; i < cantidadBusquedas; ++i) {
        std::string palabraBusqueda = generarPalabraAleatoria(int(diccionario[0].size()));

        auto inicio = std::chrono::high_resolution_clock::now();
        patriciaTrie.search(palabraBusqueda);
        auto fin = std::chrono::high_resolution_clock::now();

        double tiempo = std::chrono::duration<double, std::milli>(fin - inicio).count();
        tiempos.push_back(tiempo);
    }

    // Calcular el tiempo medio
    double tiempoMedio = 0.0;
    for (const auto& tiempo : tiempos) {
        tiempoMedio += tiempo;
    }
    tiempoMedio /= cantidadBusquedas;

    // Guardar el tiempo medio en un archivo
    std::ofstream archivo("patricia.txt", ios::app);
    archivo << tiempoMedio << std::endl;
    archivo.close();
}

int main() {//ADVERTENCIA CORRER EL SCRIPT REESCRIBIRA LOS TIEMPOS!!!
    vector<int> palabras {10,100, 1000, 10000, 100000, 1000000, 10000000,  100000000};

    int cantidadBusquedas = 500;  // Número de pruebas de búsqueda por cada cantidad de palabras
    int longitudPalabra = 10;  // Longitud fija de las palabras
    for (int palabra : palabras) {


//         Generar el diccionario
        cout<<"Prueba con  :"<<palabra<<"  palabras"<<endl;
        std::vector<std::string> diccionario = generarDiccionario(palabra, longitudPalabra);

//         Realizar las pruebas en el trie normal

          pruebaTrieNormal(diccionario, cantidadBusquedas);

//         Realizar las pruebas en el patricia trie
          pruebaPatriciaTrie(diccionario, cantidadBusquedas);


   }

    return 0;
}
