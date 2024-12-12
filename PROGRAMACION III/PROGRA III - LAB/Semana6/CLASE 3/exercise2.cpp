#include <iostream>

using namespace std;

struct Nodo{
    int _item;
    Nodo* _next;
};

int main(){
    // Cola vacia
    Nodo* front = NULL;
    Nodo* back = NULL;

    //Enqueue(3)
    Nodo* temp1 = new Nodo;
    temp1->_item = 3;
    temp1->_next = NULL;
    front = temp1;
    back = temp1;

    cout << "front = " << front->_item << endl;
    cout << "back = " << back->_item << endl;
    if (front->_next == NULL){
        cout << "vacio front" << endl;
    }
    if (back->_next == NULL){
        cout << "vacio back" << endl;
    }
    //Enqueue(5)
    Nodo* temp2 = new Nodo;
    temp2->_item = 5;
    temp2->_next = NULL;

    /// AL ACTUALIZAR EL next de BACK AUTOMATICAMENTE SE ACTUALIZA EL next de temp1 y como
    /// temp1 esta en front, front tambien se le añade los valores de temp2
    back->_next = temp2;
    /// y back deja de tener a temp1 y ahora tiene a temp2
    back = temp2;

    if (front->_next == NULL){
        cout << "vacio front" << endl;
    }
    if (back->_next == NULL){
        cout << "vacio back" << endl;
    }
    cout << "front = " << front->_item << endl;
    cout << "back = " << back->_item << endl;
    cout << "next(front) = " << front->_next->_item << endl;
}