#include "iostream"

using namespace std;

/**
A. . ¿Cuáles serían las ventajas y desventajas de usar un Stack con Listas Enlazadas respecto a
      una versión de Stack con Arrays?

    RPTA;
    - Un stack con listas enlazadas tiene ventajas si lo realizo como un double linked list:
    - Un push es eficiente y no hay desperdicio de memoria, ya que el head o tail apuntaria al siguiente o al previo
    - Su tamaño es dinamico asi que no es necesario hacer resize a cada rato
    DESVENTAJAS:
    - acceso a los elementos es demasido lento, porque tendria que ir nodo por nodo hasta encontrarlo, cosa que en un array es inmediato
    - Si quisiera limpiar todo el stack, seria muy costoso ya que igualemnte tendria que eliminar nodo por nodo, cosa que en un array no es asi
*/

/**
B. Los algoritmos InsertionSort y SelectionSort tienen una complejidad O(n^2). Sin embargo, en
    el tiempo computacional uno de ellos es más eficiente que el otro. ¿Cuál es más eficiente?
    Fundamente.



 */

/**
C. Si se tiene una colección de números enteros desordenados que fluctúan entre el rango
    [1000 - 9999] ¿Cuál sería el mejor algoritmo de ordenación a utilizar? Fundamente.


 */

/**
D. ¿Habría alguna forma de implementar la búsqueda binaria en una lista doblemente enlazada
    ordenada?

*/