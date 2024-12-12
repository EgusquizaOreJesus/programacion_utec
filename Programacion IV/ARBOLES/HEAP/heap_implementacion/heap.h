#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Heap
{
public:
    enum Type {
        MAX_HEAP, MIN_HEAP
    };

private:
    T *elements;
    int capacity;
    int n;
    Type type;

public:
    Heap(T *elements, int n, Type type=MAX_HEAP) : elements(elements), n(n), type(type)
    {
        elements = new T[capacity];

        // TODO
//        throw ("Function not implemented");
    }

    Heap(int capacity, Type type=MAX_HEAP) : capacity(capacity), type(type)
    {
        elements = new T[capacity];
        n = 0;
//        throw ("Function not implemented");
    }

    ~Heap(){ 
        // TODO  
//        throw ("Function not implemented");
    }

    void buildFromArray(T *elements, int n){
        for (int i = 0; i < n; ++i) {
            this->elements[i] = elements[i];
        }
        this->n = n;
        int padre= Parent(n-1);
        for (int i =padre; i >=0; --i) {
            heapify_down(i);
        }
//        throw ("Function not implemented");
    }
    void display(){
        for (int i = 0; i < this->n; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    int size()
    {
        // TODO
//        throw ("Function not implemented");
    }

    bool is_empty()
    {
         // TODO
//        throw ("Function not implemented");
    }

    void push(T value)
    {
        elements[n] = value;
        n++;
        heapify_up(n-1);
         // TODO
//        throw ("Function not implemented");
    }

    void pop()
    {
        std::swap(elements[0], elements[n-1]);
        n--;
        heapify_down(0);
    }

    T top()
    {
        return elements[0];
        // TODO
//        throw ("Function not implemented");
    }

    vector<T> extractTheTopK(int k){
        // TODO
//        throw ("Function not implemented");
    }

    static void sortAsc(T* arr, int n){
       // TODO
//       throw ("Function not implemented");
    }

    static void sortDesc(T* arr, int n){
       // TODO
//       throw ("Function not implemented");
    }

    void remove(int pos){
        std::swap(elements[pos], elements[n-1]);
        n--;
        heapify_down(0);
    }

private:
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    int Left(int i)
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void heapify_down(int i)
    {
        int max = i;
        int left = Left(i);
        int right = Right(i);
        if (type == MIN_HEAP){
            if (left < n && elements[left] < elements[max]){
                max = left;
            }
            if (right < n && elements[right] < elements[max]){
                max = right;
            }
            if (max != i){
                std::swap(elements[i],elements[max]);
                heapify_down(max);
            }
        }
        if (type == MAX_HEAP){
            if (left < n && elements[left] > elements[max]){
                max = left;
            }
            if (right < n && elements[right] > elements[max]){
                max = right;
            }
            if (max != i){
                std::swap(elements[i],elements[max]);
                heapify_down(max);
            }
        }


       // TODO
//       throw ("Function not implemented");
    }

    void heapify_up(int i)
    {
        if (i==0){
            return;
        }
        int padre = Parent(i);
        if (type == MAX_HEAP){
            if (elements[padre] < elements[i]){
                std::swap(elements[padre],elements[i]);
                heapify_up(padre);
            }
        }
        if (type == MIN_HEAP){
            if (elements[padre] > elements[i]){
                std::swap(elements[padre],elements[i]);
                heapify_up(padre);
            }
        }

        // TODO
//       throw ("Function not implemented");
    }
};