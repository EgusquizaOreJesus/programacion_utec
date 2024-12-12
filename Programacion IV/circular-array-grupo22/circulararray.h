#include <iostream>
#include "cmath"
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity{};
    int back{}, front{};

public:
    explicit CircularArray(int _capacity = 10);
    virtual ~CircularArray(){

        delete array;
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

    void insert(T data, int pos){ // FALTA EL INSERT WEBONAZO
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

        if(size()==1)
        {
            T temp=array[front];
            front=-1;
            back=-1;
            return temp;

        }else {
            T temp = array[front];
            front= next(front);
        }

    }
    T pop_back(){
        if(size()==1)
        {   T temp= array[back];
            front=-1;
            back=-1;
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
    int size(){
        if(back>=front)
            return back-front+1;
        else return (back+1)+(capacity-front);
    }

    T operator[](int index) const{
        int real_index = (front + index) % capacity;
        const int ga= array[real_index];
        return ga;
    }

    void sort();
    bool is_sorted();
    void reverse(){
        int tempFront = front;
        int tempBack = back;
        for (int i = 0; i < ceil(static_cast<double>(size())/2); ++i) {
            int temp = move(array[tempFront%capacity]);
            array[tempFront%capacity] = move(array[tempBack%capacity]);
            array[tempBack%capacity] = temp;
            tempBack--;
            tempFront++;
        }
    }
    string to_string(string sep=" "){
        string result;
        int current = front;
        while (current != back) {
            result += std::to_string(array[current]) + sep;
            current = next(current);
        }
        result += std::to_string(array[back]) + sep;
        return result;
    };

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

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}