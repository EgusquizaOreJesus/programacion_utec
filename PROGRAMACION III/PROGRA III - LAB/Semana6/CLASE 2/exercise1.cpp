#include "stack"
#include "iostream"

using namespace std;

class Pila{
    inline static const int MAX = 3;
    int top;
    int arr[MAX]{};
public:
    Pila(){top = -1;}
    [[nodiscard]] bool empty() const{
        if (top == -1){
            return true;
        }
        return false;
    }
    void push(int valor){
        if (!full()){
            arr[++top] = valor;
        }
        else{
            cout << "FULL!" << endl;
        }
    }
    [[nodiscard]] bool full() const{
        if (top == MAX-1){
            return true;
        }
        return false;
    }
    int pop(){
        if (!empty())
            return arr[top--];
        else{
            cout << "NO ES POSIBLE!" << endl;
            return  0;
        }
    }

};
int main(){
    Pila p;
    p.push(2);
    p.push(3);
    p.push(4);

    int e = p.pop();
    cout << "e = " << e << endl;
    return 0;
}
