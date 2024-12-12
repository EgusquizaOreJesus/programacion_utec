#include <iostream>
#include "vector"
#include "list"
#include "array"


using namespace std;
// COMPLETO

template<typename T>
class searcher{
    T a;
    void insertion_sort_vector(T &A){
        for (int j = 1; j < A.size(); ++j) {
            auto key = A[j];
            int i = j-1;
            while (A[i] > key && i>=0){
                A[i+1] = A[i];
                i = i-1;
            }
            A[i + 1] = key;
        }
    }
public:
    searcher() = default;
    searcher(T& v) {
        insertion_sort_vector(v);
        a = v;
    }
    friend int operator<<(const searcher& other, int k){
        int ind = 0;
        for(auto i:other.a){
            if (i == k){
                break;
            }
            ++ind;
        }
        if (ind == other.a.size()){ind = -1;}
        return ind;
    }
};



int main ()
{
    array<float, 8> arr = {-1, 1, 2, 3, 5, 4, 7, 8};
    searcher<array<float, 8>> s = arr;
    for (const auto& i: arr)
        cout << i << " ";
    cout << endl;               // -1 1 2 3 4 5 7 8
    cout << (s << 2) << endl;   // 2
    return 0;
}