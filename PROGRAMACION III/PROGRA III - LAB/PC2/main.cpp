#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
class Singleton {

private:
    static vector<Singleton*> Multi_instancias;
    int number;
    static int instances;
    Singleton()
    {
            number=rand()%100;
    }

public:

    int getData(){
        return number;
    }

    static Singleton* getInstance() {
        if (instances < 3) {

            auto *nueva_ins = new Singleton;
            Multi_instancias.push_back(nueva_ins);
            instances++;
            return nueva_ins;
        } else {

            Singleton* a=Multi_instancias[instances%3];
            instances++;
            return a;

        }
    }

};

vector<Singleton*> Singleton::Multi_instancias;
int Singleton::instances=0;


int main(){


        srand(time(nullptr));
        Singleton * ptr1 = Singleton :: getInstance () ;
        cout << " prt1 :  data = " << ptr1 -> getData () << endl ;
        Singleton * ptr2 = Singleton :: getInstance () ;
        cout << " ptr2 :  data  =  " << ptr2 -> getData () << endl ;
        Singleton * ptr3 = Singleton :: getInstance () ;
        cout << " ptr3 :  data  =  " << ptr3 -> getData () << endl ;
        Singleton * ptr4 = Singleton :: getInstance () ;
        cout << " ptr4 :  data =  " << ptr4 -> getData () << endl ;
        Singleton * ptr5 = Singleton :: getInstance () ;
        cout << " ptr5 :  data =  " << ptr5 -> getData () << endl ;
        return 0;


}

/*
//
// Created by bsoto on 10/02/2023.
//
#include <iostream>
#include <thread>
#include <cstdlib>
#include <iomanip>
#include <mutex>
#include <vector>
using namespace std;
mutex candado;




void producto_mean(int** A ,int **B ,int n , int m , int init, int tope , double** C , double& mean){
    int element ;
    for (int i = init; i < tope; ++i) {
        element = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k)
                element += A[i][k] * B[k][j];

            candado.lock();
            C[i][j] = element;
            candado.unlock();
            element = 0;
        }
    }


    double x = 0;
    for (int i = init; i < tope; ++i) {
        for (int j = 0; j < m; ++j) {
            x+=double(A[i][j])/double(m*n);
        }
    }

    candado.lock();
        mean += x;
    candado.unlock();


}
template<typename T>
void imp(T** m1, int rows , int cols){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <cols ; ++j) {
            cout<<setw(9)<<m1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void product(int** m1 , int**m2 , int n, int m , double** m3){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m3[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
}

void meanC(int** m1 ,  int n , int m, double&mean){

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
                mean+=m1[i][j];
        }
    }

    mean = mean/(m*n);

}



int main(){
    srand(time(nullptr));
    int n,m;

    do{
        cout<<"n:"; cin>>n;
        cout<<"m: "; cin>>m;
    }while( n == m);
    cout<<endl;


    int** A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            A[i][j] = rand()%(99);
            //A[i][j] = 1;
        }
    }

    int** B = new int*[m];
    for (int i = 0; i < m; ++i) {
        B[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            B[i][j] = rand()%(99);
            //B[i][j] = 2;
        }
    }


    auto C = new double *[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double [n];
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
        }
    }


    imp(A, n , m);
    imp(B, m , n);
    double mean = 0;


    thread t1(&producto_mean , A , B , n , m , 0 , n/2 , C ,  ref(mean));

    thread t2(&producto_mean , A , B , n , m , n/2 , n , C ,  ref(mean));
    t1.join();
    t2.join();

    imp(C, n , n);

    cout<<mean<<endl;

    auto X = new double *[n];
    for (int i = 0; i < n; ++i) {
        X[i] = new double [n];
        for (int j = 0; j < n; ++j) {
            X[i][j] = 0;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            X[i][j] = C[i][j] + mean;
        }
    }

    imp(X,n,n);

    cout<<endl<<"Otra forma:"<<endl;

    auto X1 = new double *[n];
    for (int i = 0; i < n; ++i) {
        X1[i] = new double [n];
        for (int j = 0; j < n; ++j) {
            X1[i][j] = 0;
        }
    }

    double mean2 = 0;

    thread t3(&product, A , B , n , m , X1);
    thread t4(&meanC, A , n , m , ref(mean2));

    t3.join();
    t4.join();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          X1[i][j] += mean2;
        }
    }

    cout<<endl<<mean2<<endl;

    imp(X1, n  , n);


    return 0;
}
 */