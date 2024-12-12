#include "iostream"


using namespace std;

/**
        Busqueda en profundidad (DFS)
 - usas recursividad como un stack o simplemente un stack explicitamente
        BFS:
 - Usas explicitamente una cola

 BFS Y DFS -> SE USAN PARA GRAFOS SIN PESO

 PARA GRAFOS PONDERADOS:
 BUSCAR EL CAMINO MAS CORTO, HAY UNA GRAN CANTIDAD DE ALGORITMOS:
 Dijkstra:
 - Costo: el mejor costo encuentra el dij
 operacion: muy alto para reducir su costo

 Greedy BFS:
 costo: puede ser cualquiera
 operacion: es mas optimo

 Hay un algoritmo intermedio que usa lo mejor de ambos mundos:
 Dijkstra con asteroides --> A*
 Mezcla ambos
 */

/**
            Busqueda Codiciosa (Greedy BFS)
 ¿Que es un algoritmo greedy?
    - Siempre busca la mejor solucion local, esperando tener la mejor solucion global
 Algoritmos voraces tienen dos propiedades:
  * Subestructuras optimas
  * Eleccion codiciosa

 ¿Como funciona el greedy BFS?
 - Es un algoritmo que no usa los pesos de la arista
 - Este usa sus propios valores, la heuristica (estimacion de dicho vertice hacia el final) (distancia hacia el objetivo)
 -


 A*
en kruskal el completable verifica ciclos
En A* tiene dos costos, el costo real y la heuristica
 se le suma esos dos costos y eso seria el costo final, ese costo final se lleva a la cola de prioridad --> f(n) = g(n) + h(n)


 */