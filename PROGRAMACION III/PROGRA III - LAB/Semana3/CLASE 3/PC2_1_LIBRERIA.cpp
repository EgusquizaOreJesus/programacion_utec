#include "iostream"
#include "iomanip"
#include "vector"
#include "map"
#include "set"
#include "algorithm"
#include "random"

using namespace std;
bool esCompuesto(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i == 0){
            return true;
        }
    }
    return false;
}
bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second > b.second;
}
void sorting(map<int, int>& M)
{

    // Declare vector of pairs
    vector<pair<int, int> > A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(begin(A), end(A),cmp);

    // Print the sorted value
    for (const auto &w: A){
        cout << w.first << " -> ";        // Imprimimos el key
        cout << w.second;               // Imprimimos el value
        cout << (w.second > 1 ? " veces": " vez") << endl;
    }
}

int main(){
    vector<int> v(1000);
    random_device rd;
    uniform_int_distribution<int> dis(1,300);
    map<int,bool> m2;
    map<int,int> m3;

    generate(v.begin(),v.end(),[&dis, &rd](){return dis(rd);});
    for_each(v.begin(),v.end(),[](int x){cout << setw(3) <<x << " ";});
    cout << endl << endl;
    for(auto c: v){
        if (!esCompuesto(c)){
            m2[c] = true;
        }
        else{
            m2[c] = false;
        }
    }

    /// Iteramos a traves del contenedor map
    cout << "Numero" << "\t Primo"<<endl;
    for (const auto &w: m2){
        cout << w.first << ": ";        // Imprimimos el key
        cout << "\t "<<boolalpha <<w.second;               // Imprimimos el value
        cout << endl;
    }
    for(auto c: v){
        m3[c]++;
    }
    cout << endl;
    sorting(m3);
    return 0;
}