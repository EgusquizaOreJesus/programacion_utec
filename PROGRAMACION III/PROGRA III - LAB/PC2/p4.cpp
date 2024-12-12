#include "iostream"
#include "vector"
#include "cmath"
#include "thread"
#include "chrono"
#include "iomanip"
#include "mutex"
using namespace std::chrono;
using namespace std;
mutex mtx;
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

template < typename T >
void info_hilos ( vector <T > V , int parte, int range, double & mean , double & std ) {
    int start = (parte) * (V.size()/range);
    int final = (parte+1) * (V.size()/range);
    double m = 0;
    for (int i = start; i < final; ++i) {
        m += *(next(V.begin(),i));
    }
    mean += (m/V.size());

    double s = 0;
    for ( int i = start; i < final; ++i ){
        s += pow ( *(next(V.begin(),i)) - 2.5 , 2) ;
        cout << s << endl;
    }

    std += (s/V.size());

}
int main () {
    srand(time(nullptr));
    vector < int > vec = {1,2,3,4};
//    random_ints ( vec , 10000000) ;
    double mean = 0.;
    double std = 0.;
    auto t1 = high_resolution_clock::now();
    info ( vec , mean , std ) ;
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout<<"La funcion info sin hilos toma "<< ms_double.count()<<"ms"<<endl;
    cout << " Media : " << mean << endl ;
    cout << " Desviacion Estandar : " << std << endl ;

    double mean2 = 0;
    double std2 = 0;
    info_hilos ( vec ,0,2 ,mean2 , std2 ) ;
    info_hilos ( vec ,1,2 ,mean2 , std2 ) ;
//    info_hilos ( vec ,2,4 ,mean2 , std2 ) ;
//    info_hilos ( vec ,3,4 ,mean2 , std2 ) ;
    std2 = sqrt ( std2 ) ;

    cout << " Media : " << mean2 << endl ;
    cout << " Desviacion Estandar : " << std2 << endl ;
}

