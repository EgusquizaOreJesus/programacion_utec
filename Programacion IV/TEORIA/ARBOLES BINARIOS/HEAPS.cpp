#include "iostream"

using namespace std;
/**
            HEAPS
Contenedor de n elementos
 ¿Como retornamos el maximo/min?
 - 1er opcion:
 Array/listas:
 -----------
 como hago para que el max-min sea O(1)
 asumiendo al max o min --- acceder a ello me cuesta O(1)
 cuando esta ordenado:
 max - min         O(1)
 el insert:        O(n)
 pop:              O(1)

 AVL
 ----------
 cuando me costaria:
 max- min           O(log(n))
 insert:            O(log(n))
 pop:               O(log(n))

 ARBOL CONVIENE PARA tamaños grandes, para pequeños Array/Listas


 HEAP:
 Es lo mejor de los dos mundos
 max - min      O(1)
 insert         O(n)
 pop            O(log(n))
El heap se usa para ordenar, machine learning, y para acceso rapido al elemento mas grande o pequeño
 Tiene dos propiedades:
 Tiene que ser un arbol completo
 Es que los hijos son menores que el padre, para cualquier nodo
 ---> CON ESTAS DOS PROPIEDADES TENEMOS NUESTRO HEAP
 SE HARAN DOS ARBOLES, UNO PARA EL MAX Y OTRO PARA EL MIN
 EL MAX-HEAP --> LA RAIZ SIEMPRE SERA EL MAX
 EL MIN-HEAP --> LA RAIZ SIEMPRE SERA EL MIN
el pop siempre elimina el max o min
 para el pop debemos hacer:
 1. copiar el ultimo elemento al inicio
 2.     --size
 3. aplicar heapify down a la raiz

 OBS: NO TENEMOS UN ARBOL DE NODOS --> Es un array que lo pasamos a arbolito
 En este algoritmo no usaremos NODOS, usaremos un array
 En un max-heap o min-heap, el array su pos 0 siempre tiene que ser el raiz
 Todo arbol binario balanceado su altura es O(log(n))
*/

int main(){

    return 0;
}