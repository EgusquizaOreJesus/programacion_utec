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
        this->elements = new T[n];
        capacity =n;
        buildFromArray(elements,n);

    }

    explicit Heap(int capacity, Type type=MAX_HEAP) : capacity(capacity), type(type)
    {
        elements = new T[this->capacity];
        n=0;
    }

    ~Heap(){
        delete [] elements;
    }

    void buildFromArray(T *element, int d){
        this->n=d;
        copy(element , element+n , elements);
        int index = Parent(n-1);
        for (int i = index; i >=0 ; --i) {
            // cout<<elements[i]<<endl;
            heapify_down(i);
        }

    }

    int size()
    {
        return  n;
    }

    bool is_empty()
    {
        return n==0;
    }

    void push(T value)
    {
        elements[n++]=value;
        heapify_up(n-1);
        //cout<<n<<"POR PUSH"<<endl;
    }

    T pop()
    {
        T temp= elements[0];
        elements[0]=elements[n-1];
        n--;
        heapify_down(0);



        return temp;
    }

    T top()
    {
        return elements[0];
    }

    vector<T> extractTheTopK(int k){

        vector<T> values;
        for (int i = 0; i < k; ++i) {
            values.push_back(this->pop());
        }
        return values;
    }

    static void sortAsc(T* arr, int n){
        Heap<T> heaptosort(arr , n  , MAX_HEAP);

        for (int i = n-1; i >=0; --i) {
            T temp =heaptosort.pop();

            arr[i]=temp;


        }


    }

    static void sortDesc(T* arr, int n){
        Heap<T> heaptosort(arr , n  , MAX_HEAP);


        for (int i = 0; i <n; ++i) {

            arr[i]=heaptosort.pop();

        }
    }
    [[maybe_unused]]void displaya()
    {
        for (int i = 0; i < n; ++i) {
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }

private:
    bool is_heap_max(int i){
        if(Left(i)>n and Right(i)>n)
            return true;
        if(Left(i)<=n and Right(i)>=n)
            return elements[i]>elements[Left(i)];
        if(Left(i)>=n and Right(i)<n)
            return elements[i]>elements[Right(i)];
        if(Left(i)<n and Right(i)<n)
            return elements[i]>elements[Left(i)] and elements[i]>elements[Right(i)];
        return false;
    }
    bool is_heap_min(int i){
        if(Left(i)>n and Right(i)>n)
            return true;
        if(Left(i)<=n and Right(i)>=n)
            return elements[i]<elements[Left(i)];
        if(Left(i)>=n and Right(i)<n)
            return elements[i]<elements[Right(i)];
        if(Left(i)<n and Right(i)<n)
            return elements[i]<elements[Left(i)] and elements[i]<elements[Right(i)];
        return false;
    }
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
    }
};