#include "iostream"
#include "vector"
#include "cmath"
#include "thread"
#include "chrono"
#include "iomanip"

using namespace std;

void random_ints ( vector < int >& v , int N ) {
    for ( int i =0; i < N ; i ++)
        v . push_back ( rand () % 200 - 100) ;
}
template < typename T >
void info ( vector <T > V , double & mean , double & std ) {
    for ( const T & item : V )
        mean += item ;
    mean = mean / V . size () ;
    for ( const T & item : V )
        std += pow ( item - mean , 2) ;
    std = std / V. size () ;
    std = sqrt ( std ) ;
}
int main () {
    srand(time(nullptr));
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio

    vector < int > vec ;
    random_ints ( vec , 10000000) ;
    double mean = 0.;
    double std = 0.;
    info ( vec , mean , std ) ;
    cout << " Media : ␣ " << mean << endl ;
    cout << " Desviacion ␣ Estandar : ␣" << std << endl ;
    std::chrono::duration<double, std::milli> t = fin - inicio;
    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin
    cout << "binary_search (time) = " <<setprecision(20)<<t.count() << "ms" << endl;
}