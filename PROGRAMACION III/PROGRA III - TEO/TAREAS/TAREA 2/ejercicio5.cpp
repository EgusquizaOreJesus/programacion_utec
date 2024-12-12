#include "iostream"
#include "vector"

using namespace std;

template<typename ...Ts>
auto suma_producto(Ts ... ts){
    vector<double> v;
    (v.push_back(ts),...);
    double prod = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i == v.size()-1){
            prod = prod + v[i];
            break;
        }
        prod = v[i]*v[i+1] + prod;
        i++;
    }
    return prod;
}

// COMPLETO

int main(){
    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25
    std::cout << suma_producto(1) << endl; // El resultado seria: 1
    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46
    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0

    return 0;
}