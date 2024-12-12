#include <iostream>

/**
            Diccionarios
Las busquedas se hacen por las llaves y obtengo su valor
Keys           ---->         Values
Aplicaciones
 Indices en base de datos relacionales
 Indexacion de datos semiestructurados: JSON / BSON
 Representacion de Matrices Dispersas

 ---> BUSQUEDA BINARIA EN LISTAS ENLAZADAS (RETO)
 Arrays Asociativos
 Skip List:-->BUSQUEDA BINARIA EN LISTA ENLAZADA:

 Si o si la lista tiene que estar ordenada
**/

/**
TABLA HASH:
 ---> El coraxon de hash es su funcion
 ---> Necesito siempre un array
 La clave debe ser mapeada a un indice del array
 RESTRICCION:
 - Las claves deben ser unicas
 - No sabemos en que posicion se almacenan
 ¿Que es una funcion has?
 Es un algoritmo matematico que transforma cualquier key a un codigo unico.
 Este codigo es utilizado como indice en el hash table.
 Mapee cada entrada a un valor de hash unico --> ESO ES LO QUE NOS IMPORTA
 ¿Que problemas podriamos tener con esa funcion?
 - Procesar la key puede ser dificil para ciertos tipos de datos
 Manejar colisiones cuando dos keys tienen el mismo indice
 Espacio-tiempo tradeoff
 Las funciones hashing no son fiables puede que para dos llaves diferentes genere
 el mismo codigo hash --> ESO SE LLAMA COLISION
 Que significa que un codigo hashing es estable
 Cuando genere la misma llave me de el mismo codigo hash
 PROPIEDADES:
 Estable: El output siempre deberia ser el mismo para el mismo input (INVARIANTE)
 Uniforme: Los valores hash deben ser distribuidos de manera uniforme (reducir colisiones)
 ---> para llaves diferentes debe tener codigos diferentes
 ---> ejemplo
 hash("cat") = 312
 hash("tac") = 312
 ---> NO ES UNIFORME PORQUE TIENEN MISMO CODIGO PARA DIFERENTES LLAVES, AUNQUE SI ES ESTABLE
 COMO CORREGIR:

 Eficiencia: Debe ser balanceado de acuerdo a las necesidades en espacio y tiempo

 ¿Como agregamos datos?
 Se inicio con un tamaño fijo del array, y se genera el hash code
 int capacity = 10;
 int hashCode = getHashCode(key);
 int index = hashCode % capacity;
 array[index] = value

 Hay dos tecnicas para hacer esto
 - Open Addressing ---> NO SIRVE
 - Chaining--> Si el espacio ya esta ocupado, entonces se agrega el elemento a la lista enlazada

 **/

/**
V(x) = x*
 */


using namespace std;
int main() {
    srand(time(nullptr));
    int n = rand()%100;
    cout << n << endl;

    int n2 = rand()%10;
    cout << n2 << endl;
    return 0;
}
