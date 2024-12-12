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
        if(type==MAX_HEAP)
        {
            if(!is_heap_max(i))
            {//cout<<"EL VALOR DE "<<Left(i)<<" "<< Right(i)<<"  "<<n<<endl;
                int temp , indextemp;
                if(Left(i)<=n and Right(i)>=n)
                {
                    temp = elements[Left(i)];
                    indextemp = Left(i);

                }
                if(Left(i)>=n and Right(i)<n)
                {
                    temp =  elements[Right(i)];
                    indextemp = Right(i);
                }
                if(Left(i)<n and Right(i)<n)
                {
                    temp = max(elements[Left(i)], elements[Right(i)]);
                    indextemp=(elements[Left(i)]>elements[Right(i)])? Left(i): Right(i);

                }
                elements[indextemp]=elements[i];
                elements[i]=temp;
                heapify_down(indextemp);

            }else return;

        }

        if(type==MIN_HEAP)
        {

            if(!is_heap_min(i))
            {
                int temp , indextemp;
                if(Left(i)<=n and Right(i)>=n)
                {
                    temp = elements[Left(i)];
                    indextemp = Left(i);

                }
                if(Left(i)>=n and Right(i)<n)
                {
                    temp =  elements[Right(i)];
                    indextemp = Right(i);
                }
                if(Left(i)<n and Right(i)<n)
                {
                    temp = min(elements[Left(i)], elements[Right(i)]);
                    indextemp=(elements[Left(i)]<elements[Right(i)])? Left(i): Right(i);

                }

                elements[indextemp]=elements[i];
                elements[i]=temp;
                heapify_down(indextemp);

            }else return;

        }
    }

    void heapify_up(int i)
    {
        if(type==MAX_HEAP)
        {
            while (elements[i]>elements[Parent(i)])
            {
                T temp=elements[i];
                elements[i]=elements[Parent(i)];
                elements[Parent(i)]=temp;
                i = Parent(i);

            }

        }

        if(type==MIN_HEAP)
        {
            while (elements[i]<elements[Parent(i)])
            {
                T temp=elements[i];
                elements[i]=elements[Parent(i)];
                elements[Parent(i)]=temp;
                i = Parent(i);

            }

        }
    }
};