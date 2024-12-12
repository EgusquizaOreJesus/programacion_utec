#include <iostream>

/**
COLA DE PRIORIDAD
En este cola, los elementos se meten, no importan como lo metas
Pero cuando quieras retirar hacer "pop", se retira el que tenga max prioridad
Para aquello al input le asignamos una prioridad

 Cuando:
 - push(): añade un elemento y se ubica en la cola segun su prioridad --> el push tiene complejidad O(n)
 - pop(): retira el elemento con mayor prioridad --> el pop es O(1)
 - top(): retorna el elemento con mayor prioridad --> el top es O(1)

 ESTA COLA DE PRIORRIDAD SE PUEDE USAR EN CONTENEDOR
 EL HEAP- ARBOL ES UNA ESTRUCTURA QUE ES MAS EFICIENTE Y MAS SE UTILIZA EN COLAS DE PRIORIDAD
 QUE TIENE O(log(n)) para push y pop, y para top() --> O(1)
 **/

/**
SELF ORGANIZING LIST
 Listas auto_organizadas para busquedas frecuentes
 Contenedor lineal cuando conviene utilizar busquedas cuando buscas por inicio y final
 Pero
 Hay otras estructuras que son mas eficientes arboles, etc que mejor se usan para busqueda
 */

/**
En estas busquedas frecuentes, solo iteraras una vez ya que en la siguiente busqueda
 El elemento estara al inicio, entonces cuando siga buscando ese mismo elemento
 Ya la busqueda sera constante
 PERO SU DESVENTAJA ES QUE SI BUSCO ELEMENTOS NO FRECUENTES COMPLICARIA LA BUSQUEDA
 PORQUE YA ESTARIA MOVIENDO LOS FRECUENTES
 */
#include "vector"
int main() {
    std::vector<int> v = {1,2,3};
    std::cout << v.begin() << std::endl;
    return 0;
}
