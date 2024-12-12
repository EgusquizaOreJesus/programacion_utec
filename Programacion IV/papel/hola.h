////
//// Created by Jesus on 2/04/2023.
////
//
#ifndef PAPEL_HOLA_H
#define PAPEL_HOLA_H
#include <iostream>

template<typename T>
class arraysss{
    T* array;
    int capacity;
    int back, front;
public:
    arraysss(int size);
    virtual ~arraysss(){
        delete[] array;
    }
    T& operator[](int x);
    const T& operator[](int x) const;
    friend T& operator[] <>(arraysss<T>* arr, int x);
    friend const T& operator[] <>(const arraysss<T>* arr, int x);
};

template <typename T>
T& arraysss<T>::operator[](int x) {
    return array[(front+x)%capacity];
}

template <typename T>
const T& arraysss<T>::operator[](int x) const {
    return array[(front+x)%capacity];
}

template <typename T>
T& operator[](arraysss<T>* arr, int x) {
    return (*arr)[x];
}

template <typename T>
const T& operator[](const arraysss<T>* arr, int x) {
    return (*arr)[x];
}


template <class T>
arraysss<T>::arraysss(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}
//template <typename T>
//T& operator[](arraysss<T>* arr, int x) {
//    return (*arr)[x];
//}
//
//template <typename T>
//const T& operator[](const arraysss<T>* arr, int x) {
//    return (*arr)[x];
//}
#endif //PAPEL_HOLA_H

