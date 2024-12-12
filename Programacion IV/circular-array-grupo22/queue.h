#include "circulararray.h"

template <typename T>
class QueueArray : private CircularArray<T> {
public:
    explicit QueueArray(int size_): CircularArray<T>(size_){};

    void push(int data_){
        this->push_back(data_);
    }
    T pop(){
        this->pop_front();
    }
    string display(){
        return this->to_string();
    }
};