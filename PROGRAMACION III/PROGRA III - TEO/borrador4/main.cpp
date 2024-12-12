#include <initializer_list>
#include <utility>
#include <memory>
#include <vector>
#include "iostream"
#include "memory"
using namespace std;
template<typename T , int sz>
class fixed_stack_pusher;

template<typename T, int sz=0>
class  fixed_stack {
private:
    vector<T> data;
    int tam;
public:
    void setTope(int tope) {
        tam = tope;
    }

    fixed_stack(){
        tam = 0;
    }

    fixed_stack(initializer_list<T> lst) {
        for (const auto &item: lst) {
            push(item);
        }
    }

    [[nodiscard]] bool empty() const {

        return tam == 0;
    }
    [[nodiscard]] const T& top() const  {
        if(!empty())
            return *next(data.begin() , tam - 1);
        return data[0];
    }
    void pop()
    {
        --tam;
    }
    bool push(T element)
    {
        if(tam <sz){
            data.push_back(move(element));
            tam++;
            return true;
        }
        return false;
    }
    int size()
    {
        return tam;
    }
    friend  class  fixed_stack_pusher<T,sz>;
};
template<typename T , int sz>
class fixed_stack_pusher
{
public:
    using value_type= T;
    using reference  = T&;
    using pointer = const T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;
private:
    fixed_stack<T,sz> * stack;
    int indice;
public:
    explicit fixed_stack_pusher(fixed_stack<T,sz> & s, int i = 0) : stack(&s), indice(i) {
        s.data.resize(sz);
    }
    fixed_stack_pusher& operator++() {
        indice++;
        stack->setTope(indice);
        return *this;
    }

    T& operator*() {
        return *next(this->stack->data.begin(), indice);
    }
    fixed_stack_pusher& operator=( T& value) {

        stack->data[stack->tam++]=value;
        return *this;
    }
};
int main(){
    fixed_stack<int, 5> fs1 {1, 2, 3, 4, 5};
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }


    return 0;
}