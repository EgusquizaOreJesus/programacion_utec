#include "iostream"
#include "algorithm"
#include "vector"
#include "random"
#include "iomanip"
#include "map"
using namespace std;


//    // Print the sorted value
//    for (const auto &w: A){
//        cout << w.first << " -> ";        // Imprimimos el key
//        cout << w.second;               // Imprimimos el value
//        cout << (w.second > 1 ? " veces": " vez") << endl;
//    }
/// OBS:
/// map: este map lo ordena de mayor a menor los valores automaticamente
/// unordered_map: los deja los valores como esta

/// acordar map <key,value>
int main(){
    random_device rd;
    uniform_int_distribution<int> dis(1,199);
    vector<int> v(1000);
    unordered_map<int,size_t> m1;
    // generate vector of 1000 values
    generate(v.begin(),v.end(),[&dis, &rd](){return dis(rd);});

    // Print vector
    for_each(v.begin(),v.end(),[](int x){cout << setw(3) << x << " ";});
    cout << endl;

    for (auto elem: v){
        string conver_ele = to_string(elem);
        m1[elem] = conver_ele.size();
    }

    /// PRINT MAP
    for (const auto &w: m1) {
        cout << w.first << " -> ";        // Imprimimos el key
        cout << w.second;               // Imprimimos el value
        cout << endl;
    }
    /// SEPARAR ELEMENTOS POR CIFRAS
    vector<int> elem_1cifra;
    vector<int> elem_2cifra;
    vector<int> elem_3cifra;
    for (const auto& elem_map: m1){
        switch (elem_map.second) {
            case 1:
                elem_1cifra.push_back(elem_map.first);
                break;
            case 2:
                elem_2cifra.push_back(elem_map.first);
                break;
            case 3:
                elem_3cifra.push_back(elem_map.first);
                break;
        }

    }
    cout << "3 cifras: " << endl;
    for_each(elem_3cifra.begin(),elem_3cifra.end(),[](int x){cout << setw(3) <<x << " ";});
    cout << endl;
    cout << "2 cifras: " << endl;
    for_each(elem_2cifra.begin(),elem_2cifra.end(),[](int x){cout << setw(3) << x << " ";});
    cout << endl;
    cout << "1 cifra: " << endl;
    for_each(elem_1cifra.begin(),elem_1cifra.end(),[](int x){cout << setw(3) <<x << " ";});
    cout << endl;
    return 0;
}