#include <iostream>
// EN ESTA CLASE SE VE LA DIFERENCIA ENTRE CONSTRUCTOR MOVE Y COPY

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// RECUERDA
// LA MEMORIA DINÁMICA SE PUEDE MANEJAR o IMPLEMENTAR DE 3 FORMAS
// 1. Uso de punteros regulares         -->     Hace un uso compacto de la memoria (poca memoria) - dificil de manejar
// DESVENTAJAS DE LA MEMORIA DINÁMICA:
// Generan dos tipos de errores:
//  - Tangle memory (un puntero con referencia incorrecta) --> osea que tiene una direccion incorrecta, apunta a un lugar incorrecto
//          Ejm:  ocurre cuando creas un puntero que no apunta a ningún lado, NO LO INICIALIZAMOS

//  - Memory leak   (fuga de memoria) --> ósea que la memoria no lo podemos REUTILIZAR, mientras se ejecuta el programa
//          Ejm: ocurre cuando crear un puntero dinamico y te OLVIDAS DE LIBERAR LA MEMORIA (delete)

// 2. Uso de punteros inteligentes      -->
//  VENTAJAS:
//  - Se tiene un control mejor que en el caso de punteros regulares
//  - Reduce significativamente el problema de la referencia incorrecta y de la fuga de memoria (no lo reduce al 100%, pero si la mayoria)
//  DESVENTAJAS:
//  - Su sintaxis es más extensa, hay muchas palabras claves
//  - Hay tres tipos de punteros estandar: UNICOS, COMPARTIDOS, DEBILES (unique, shared, weak)
//      - Si utilizamos los punteros compartidos, necesitamos MÁS MEMORIA
//  - Es menos compacto

//
// 3. Uso de contenedores (vector,list,map)
// VENTAJAS
//  - Controlan automáticamente la memoria dinamica (es garantía de que no va a haber muchos errores, ósea de un manejo correcto de memoria dinamica)
//  - Son faciles de manejar
//  - Nos permiten utilizar una serie de algoritmos disponibles en la liberia estandar
// DESVENTAJAS
//  - No son tan compactos, incluyen una serie de estados adicionales, incluyen un conjunto de metodos