#include <iostream>
#include "array"
using namespace std;

template<typename T>
void init_array(T &arr);
template<typename T>
void init_array(T &arr,int k);
template<typename T>
void init_array(T &arr,int k, int p);
template<typename T>
void init_array(T &arr,int k, int f,int p);


// PREGUNTA 9;
int main() {
    array<int, 4> arr = { 40, 10, 25, 20 };
    for(auto i:arr){
        cout << i;
    }
    cout << arr.size();



}
template<typename T>
void init_array(T &arr){

    int temp = 0;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=1;
    }
}
template<typename T>
void init_array(T &arr,int k){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=1;
    }
}

template<typename T>
void init_array(T &arr,int k, int p){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=p;
    }

}

template<typename T>
void init_array(T &arr,int k, int f,int p){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        if (temp == f){ break;}
        arr[i] = temp;
        temp+=p;
    }
}