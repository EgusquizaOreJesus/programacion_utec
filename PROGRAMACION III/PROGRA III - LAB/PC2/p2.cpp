#include "vector"
#include "iostream"

using namespace std;


template < typename T >
void foo ( vector <T >& V ) {
    int n = V . size () ;               // O(1)
    int i = ( n - 1) / 2;               // O(1)
    int j = n / 2;                      // O(1)
    T tmp ;
    while ( i >= 0 && j <= (n -1) ) {   // O(n)
        tmp = V [ i ];                  //
        V [ i ] = V[ j ];
        V [ j ] = tmp ;
        i --;
        j ++;
    }
}
/// 1. foo al vector v realiza un proceso invertir los numeros

/// 4. foo tiene una complejidad algoritmica de O(n)

int main(){
    vector<int> v = {1,2,3,4};
    foo2(v);
    for(auto e: v){
        cout << e << " ";
    }


    return 0;
}
