#include "map"
#include "iostream"
#include "algorithm"
#include "vector"
#include "random"
#include "iomanip"

using namespace std;

bool esPrimo(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i==0){
            return false;
        }
    }
    return true;
}

bool order_descendente(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

void sort_map(const map<int,int>& M){
    vector<pair<int,int>> v;
    for(const auto& elem: M){
        v.emplace_back(elem);
    }
    sort(v.begin(),v.end(), order_descendente);
    // PRINT VECTOR SIMILAR A MAP:
        for (const auto &w: v){
       cout << w.first << " -> ";
       cout << w.second;
       cout << (w.second > 1 ? " veces": " vez") << endl;
    }
}
template<typename Container_pair>
void print_container_primos(Container_pair X){
    for (const auto &w: X) {
        cout << w.first << " -> ";
        cout << boolalpha << w.second << endl;
    }
    cout << endl;
}
int main(){
    random_device rd;
    uniform_int_distribution<int> dis(1,99);
    vector<int> v(1000);
    map<int,bool> m1;
    map<int,int> m2;

    generate(v.begin(),v.end(),[&dis,&rd](){return dis(rd);});
    for_each(v.begin(),v.end(),[](int x){cout << setw(5) << x << " "; });
    cout << endl;

    for (const auto elem: v){
        m1[elem] = esPrimo(elem);
        m2[elem]++;
    }
    print_container_primos(m1);

    sort_map(m2);
    return 0;
}
