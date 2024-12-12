//
// Created by rudri on 10/11/2020.
//

#include <initializer_list>
#include <utility>
#include <memory>
#include <vector>
#include "iostream"
using namespace std;
template<typename T , int sz>
class fixed_stack_pusher;

template<typename T, int sz=0>
class  fixed_stack {
private:
    T *data;
    int tam = 0;

public:
    void setTope(int tope) {
        tam = tope;
    }

    fixed_stack() {
        data = new T[sz];
    }

    fixed_stack(initializer_list<T> lst) {
        data = new T[sz];
        for (const auto &item: lst) {
            if (!push(item)) {
                break;
            }
        }
    }

    [[nodiscard]] bool empty() const {
        cout << "empty";

        return tam == 0;
    }
    [[nodiscard]] const T& top() const  {
        cout << "top";
        if(!empty())
            return *(data + tam - 1);
        return *data;
    }
    void pop()
    {
        cout << "pop";
        --tam;
    }
    bool push(T element)
    {
        cout << "push";
        if(tam <sz){
            data[tam]=std::move(element);
            tam++;
            return true;
        }
        return false;
    }
    int size()
    {
        cout << "size";
        return tam;
    }
    friend  class  fixed_stack_pusher<T,sz>;
};
template<typename T , int sz>
class fixed_stack_pusher
{
private:
    fixed_stack<T,sz> * stack;
    int indice;
public:
    explicit fixed_stack_pusher(fixed_stack<T,sz> & s, int i = 0) : stack(&s), indice(i) {
        cout << "hol4";

    }
    fixed_stack_pusher& operator++() {
        cout << "operator++" << endl;
        indice++;
        stack->setTope(indice);
        cout << *(stack->data + indice) << endl;
        return *this;
    }

    T& operator*() {
        cout << "operator*()"<<endl;
        return *(stack->data + indice);
    }
    fixed_stack_pusher& operator=( T& value) {
        cout << "hol5";

        stack->data[stack->tam++]=value;
        return *this;
    }
};

int main(){
    fixed_stack<int, 100> fs1;
    std::vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    copy(begin(vc1), end(vc1), fixed_stack_pusher(fs1));
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }
    // 8 7 6 5 4 3 2 1

    return 0;
}