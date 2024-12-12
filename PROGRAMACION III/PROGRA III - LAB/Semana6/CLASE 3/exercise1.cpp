#include "iostream"

using namespace std;
/// Una COLA tiene dos extremos: la parte delantera (FRONT) y la trasera (BACK).
/// Los elementos se retiran de la parte delantera, y se insertan por la parte trasera.
class Cola{
    inline static const int MAX = 10;
    int front;      // parte delantera
    int back;       // parte trasera
    int arr[MAX];
public:
    Cola(){
        back = -1;
        front = -1;
    }
    void enqueue(int e){
        if (full())
            cout << "FULL!" << endl;
        else{
            if (front == -1){ front = 0;}
            back++;
            arr[back] = e;
        }
    }
    int dequeue(){
        if (empty()){
            cout << "EMPTY!" << endl;
            return -1;
        }
        else{
            int e = arr[front];     // elemento de la parte delantera
            if (front >= back){
                front = -1;
                back = -1;
            }
            else
                front++;
            cout << "e = "<< e;
            cout << " deleted!" << endl;
            return e;
        }
    }
    bool empty(){
        if (front == -1)
            return true;
        return false;
    }
    bool full(){
        if (front == 0 && back == MAX - 1)
            return true;
        return false;
    }
    void displayQueue(){
        if (empty())
            cout << "Queue empty!" << endl;
        else{
            cout << "\nQUEUE:" << endl;
            for (int i=front; i <= back; i++){
                if (i == front)
                    cout << arr[i] << " <= HEAD" << endl;
                else if (i == back)
                    cout << arr[i] << " <= BACK" << endl;
                else
                    cout << arr[i] << endl;
            }
        }
    }

};
int main(){
    Cola myqueue;

    myqueue.dequeue();
    myqueue.enqueue(8);     // front -> 0  y back -> 0
    myqueue.enqueue(3);     // front -> 0  y back -> 1
    myqueue.enqueue(7);     // front -> 0  y back -> 2
    myqueue.enqueue(2);     // front -> 0  y back -> 3
    myqueue.enqueue(4);     // front -> 0  y back -> 4
    myqueue.dequeue();         // e:8 front -> 0 y back = 4
    myqueue.dequeue();         // e:3 front -> 1 y back = 4
    myqueue.dequeue();         // e:7 front -> 2 y back = 4
    myqueue.dequeue();         // e:2 front -> 3 y back = 4
    myqueue.dequeue();         // e:4 front -> 4 y back = 4 --> front = -1 y back = -1
    myqueue.dequeue();
    myqueue.displayQueue();
}
