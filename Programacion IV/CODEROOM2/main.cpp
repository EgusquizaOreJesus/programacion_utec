#include <iostream>
#include "cmath"
using namespace std;

template <class T>
class CircularArray
{
public:

    class CIterator
    {
    public:
        using reference = T&;
    private:
        int current;
        CircularArray<T>* array;

    public:
        CIterator(){
            current = -1;
        }

        explicit CIterator(int index, CircularArray<T> *array = nullptr){
            current = index;
            this->array = array;
        }

        bool operator != (const CIterator &other){
            return current != other.current;
        }

        CIterator& operator++(){
            ++current;
            return *this;
        }
        CIterator& operator--(){
            --current;
            return *this;
        }
        reference operator*(){
            return (*array)[current];
        }
    };
    typedef CIterator iterator;
private:
    T *array;
    int capacity{};
    int back{}, front{};

public:
    iterator begin(){

        return iterator (0, this);
    }
    iterator end(){
        return iterator (size(), this);

    }
    explicit CircularArray(int _capacity = 10){
        this->capacity = _capacity;
        this->array = new T[_capacity];
        this->front = this->back = -1;
    };
    virtual ~CircularArray(){
        delete array;
    }

    [[maybe_unused]] T Front(){
        return array[front];
    }
    [[maybe_unused]] T Back(){
        return array[back];
    }
    void push_front(T data) {
        if (is_full()) {
            resize();
        }

        if (is_empty()) {
            front = 0;
            back = 0;
            array[front] = data;
        }
        else {
            front= prev(front);
            array[front]=data;
        }
    }
    void push_back(T data){
        if (is_full()) {
            resize();
        }

        if(is_empty())
        {
            front=0;
            back=0;
            array[back]=data;
        } else {
            back= next(back);
            array[back]=data;
        }
    }

    void insert(T data, int pos){
        if (is_full()){
            resize();
        }
        if (pos> size()){
            push_back(data);

            return;
        }
        if (is_empty()) {
            front = 0;
            back = 0;
            array[front] = data;
            return;
        }
        if (pos == 1){
            push_front(data);
        }
        else if (pos == size()){
            push_back(data);
        }
        else{
            int index = pos;
            for (int i = size(); i >= index; --i) {
                array[(i+front)%capacity] = array[(i-1+front)%capacity];
            }
            array[(index-1+front)%capacity] = data;
            back = next(back);
        }
    }

    T pop_front(){
        if(is_empty())
        {
            cout<<"NO HAY ELEMENTOS POP IMPOSIBLE..."<<endl;
            return -1;
        }

        if(size()==1)
        {
            T temp=array[front];
            front=-1;
            back=-1;
            return temp;

        }else {
            T temp = array[front];
            front= next(front);
            return temp;
        }

    }
    T pop_back(){
        if(is_empty())
        {
            cout<<"NO HAY ELEMENTOS POP IMPOSIBLE..."<<endl;
            return -1;
        }

        if(size()==1)
        {   T temp= array[back];
            front=-1;
            back=-1;
            return temp;
        }else {
            T temp = array[back];
            back= prev(back);
            return temp;
        }

    }

    bool is_full(){
        return size()==capacity;
    }
    bool is_empty(){
        return back==-1 and front == -1 ;
    }
    [[nodiscard]] virtual int size() const{

        if(back>=front)
            return back-front+1;
        else return (back+1)+(capacity-front);
    }

    T& operator[](int index) const{
        int tam=size();
        if(index> tam or index <0)
            throw std::out_of_range("El indice esta esta fuera del rango del arreglo");

        return array[(front + index)%capacity];


    }

    [[maybe_unused]] void clear(){
        delete array;
        back = front = -1;
        array = new T[capacity];
    }
private:
    int next(int index){
        return (++index)%capacity;
    }
    int prev(int index){

        if(index == 0)
        {
            return capacity-1;
        }
        else return index-1;

    }
    void resize(){
        T temp[this->capacity];
        for (int i = 0; i < capacity; ++i) {
            temp[i] = array[(i+front)%capacity];
        }
        delete array;
        array = new T[capacity*2];
        for (int i = 0; i < capacity; ++i) {
            array[i] = temp[i];
        }
        front = 0;
        back = capacity-1;
        capacity *= 2;
    }

};



int main(){
    CircularArray<int> elementos;
    elementos.push_front(2);
    elementos.push_front(4);
    elementos.push_front(6);
    elementos.push_back(8);
    elementos.push_back(10);

    CircularArray<int>::iterator ite = elementos.begin();
    ++ite; ++ite; --ite; --ite;
    CircularArray<int>::iterator ite2 = ++ite;

    for( ; ite2 != elementos.end(); ++ite2){
        cout<<*ite2<<endl;//4, 2, 8, 10
    }

    return 0;
}