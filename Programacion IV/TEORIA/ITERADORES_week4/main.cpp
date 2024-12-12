#include <iostream>
#include "forward_list"
/**
        ITERADORES
¿Para que me sirve los iteradores?
Para abstraernos en un codigo redundante
Usar iteradores nos lleva a dejar los contenedores independientes, por tanto no hacemos asumpciones del acceso
 --> begin: empieza al inicio
 --> end: es el siguiente despues del final

 Iterador implicito: proveen una manera de iterar sin tener que declarar al iterador
 Que operadores debemos implementar en un iterador
 - begin()
 - end()
 - operator++() --> retorna ya avanzado
 - operator--() --> returna el new iterator after decrementing a positions, retorna ya retrocido
 - operator*()  --> returna el contenido de el iterador current position
 - operator!=() --> returna true, si dos iteradores son diferentes
 - operator=() --> asignar un iterador a otro

 OBS:
 stack, queue, priority queue --> NO SOPORTAN ITERADORES

 -- Array simple --
declaracion : int current;
begin()	: current = 0;
end()		: current = size;
++()		: ++current
--()		: --current
*()		: array[current]

-- Array circular --
declaracion : int current;
begin()	: current = front
end()		: (back+1)%capacity -- next(back)
++()		: current = next(current)
--()		: current = prev(current)
*()		: array[current]

-- Forward List -- simplemente enlazada
declaracion : Node<T>* current;
begin()	: head
end()		: nullptr
++()		: current = current->next
--()		: NO SOPORTA :C
*()		: current -> data

-- Double List --
declaracion : Node<T>* current;
begin()	: head
end()		: nullptr
++()		: current = current->next
--()		: current = current->prev
*()		: current -> data

-- Circular List --
declaracion : Node<T>* current;
begin()	: head->next
end()		: head->prev->next = head
++()		: current = current->next
--()		: current = current->prev
*()		: current -> data
**/
using namespace std;
int main() {
    forward_list<int> lista;
    lista.push_front(8);
    lista.push_front(5);
    lista.push_front(6);

    for (int i = 0; i < ; ++i) {

    }

    return 0;
}
