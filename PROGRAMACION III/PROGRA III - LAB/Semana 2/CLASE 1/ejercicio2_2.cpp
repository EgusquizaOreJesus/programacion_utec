#include "iostream"
#include <vector>
#include "random"
using namespace std;

template<class T>
class RandomVector{
private:
    vector<T> vec;
public:
    explicit RandomVector(int n){
        for(int i=0; i<n; i++){
            T z = rand() % 101 - 50; // z : [-50,50]
            vec.push_back(z / 10);
        }
    }
    void print(){
        for(auto e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main(){
    srand(time(nullptr));
    RandomVector<int> v1(10);
    RandomVector<float> v2(10);

    v1.print();
    v2.print();

    return 0;
}