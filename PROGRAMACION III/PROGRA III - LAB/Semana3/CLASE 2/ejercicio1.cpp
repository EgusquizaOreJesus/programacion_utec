#include "iostream"
#include "vector"
#include "random"
#include "algorithm"

using namespace std;

template<typename T>
class PrintVector{
    char end_;
public:
    explicit PrintVector(char end = ' '):end_(end){};
    void operator() (T x) const{
        cout << x << end_;
    }
};



int main(){
    vector<int> v(10);
    random_device rd;
    uniform_int_distribution<int> dis(0,99);
    for (int i = 0; i < 10; ++i) {
        v[i] = dis(rd);
    }

    for_each(v.begin(),v.end(),PrintVector<int>(' '));
    cout << endl;

    /// CALCULANDO EL MAX VALOR MEDIANTE ITERADORES
    int max_val = *(v.begin());
    for(auto it=next(v.begin()); it != v.end(); ++it){
        if (*it > max_val){
            max_val = *it;
        }
    }

    cout << "Max valor: " << max_val << endl;
    /// CALCULANDO EL PROMEDIO MEDIANTE ITERADORES
    float sum = 0;
    for(auto it=v.begin(); it != v.end(); it++){
        sum+=float(*it);
    }
    cout << "Promedio: " << (sum/float(v.size())) << endl;


    return 0;
}