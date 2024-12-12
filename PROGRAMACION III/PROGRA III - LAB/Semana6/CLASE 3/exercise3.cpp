#include "iostream"

using namespace std;
/// Una COLA tiene dos extremos: la parte delantera (FRONT) y la trasera (BACK).
/// Los elementos se retiran de la parte delantera (FRONT), y se insertan por la parte trasera (BACK).
struct Nodo{
    int _item;
    Nodo* _next;
};

class Queue{
    Nodo* front;
    Nodo* back;
public:
    Queue(){
        front =NULL;
        back = NULL;
    }
    int dequeue(){
        if (!empty()){
            Nodo* temp = front;
            int out = front->_item;
            front = front->_next;

            delete temp;
            if (front == NULL)
                back = NULL;
        }
        else
            cout << "EMPTY!" << endl;
        return -1;

    }
    void enqueue(int valor) {
        Nodo *temp = new Nodo;
        temp->_item = valor;
        temp->_next = NULL;
        if (back == NULL){
            front = temp;
            back = temp;
        }
        else{
            back->_next = temp;
            back = temp;
        }

    }
    bool empty(){
        if (front == NULL)
            return true;
        return false;
    }
    void displayQueue(){
        if (empty())
            cout << "Queue empty!" << endl;
        else{
            Nodo* temp = front;
            while (temp != NULL){
                cout << temp->_item;
                temp = temp->_next;
                if (temp == NULL)
                    cout << " <= BACK";
                cout << endl;
            }
        }
    }
};
int main(){
    Queue myqueue;


    myqueue.dequeue();
    myqueue.enqueue(8);
    // BACK NULL
    // temp: item -> 8 y next -> NULL
    // front = temp  y back = temp
    myqueue.enqueue(3);
    // temp: item -> 3 y next -> NULL
    // BACK NO NULL
    // back: back->next = temp ----> front->next->item = 3
    // y back = temp
    myqueue.enqueue(7);

    myqueue.enqueue(2);
    myqueue.enqueue(4);
    myqueue.dequeue();
    myqueue.displayQueue();


}