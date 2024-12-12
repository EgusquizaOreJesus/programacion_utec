#include "stack"
#include "iostream"

using namespace std;

class Nodo{
    int _valor;
    Nodo* _next;
public:
    Nodo(int valor, Nodo* next):_valor(valor),_next(next){}
    [[nodiscard]] int getValor() const{
        return _valor;
    }
    Nodo* getNext(){
        return _next;
    }


};
int main(){
    Nodo* n1 = new Nodo(3, NULL);
    cout << "valor = " << n1->getValor() << endl; // resultado: 3

    Nodo* n2 = new Nodo(5, n1);
    cout << "valor = " << n2->getValor() << endl; // resultado: 5

    cout << "valor = " << n2->getNext()->getValor() << endl; // resultado: 3

    Nodo* top = n2;
    top = n2->getNext();
    delete n2;
    delete top; // delete n1

    //delete n1; // Error: double free
}
