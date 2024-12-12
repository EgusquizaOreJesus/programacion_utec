#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <random>
#include "SortingAlgoritmos.h"
using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point ObtenerTiempo()
{
    return high_resolution_clock::now();
}

void inicializar_vector(vector<int> & new_vector, int size)
{

    for (int i = 0; i < size; ++i) {
        new_vector[i]=rand()%10000;
    }
}
void inicializar_vector(vector<int> & new_vector, int size , int rango)
{

    for (int i = 0; i < size; ++i) {
        new_vector.push_back(rand()%rango);
    }
}
int main(){
    srand(time(nullptr));
    int init =10;
    int final = 100000;
    // int Numero_pruebas=1;
    vector<double> tiempos;
    double tiempo;



    /* auto  inicio = ObtenerTiempo();
     selection_sort(nueva_prueba);
     auto finaru = ObtenerTiempo();

     auto duracion= duration_cast<duration<double>>(finaru-inicio);

     tiempo=duracion.count();
     tiempos.push_back(tiempo);
     cout<<duracion.count();*/
    for (int i = init; i <= final ; ++i) {
        vector<int> nueva_prueba(i);

        inicializar_vector(nueva_prueba,i);


        auto  inicio = ObtenerTiempo();
        selection_sort(nueva_prueba);
        auto finaru = ObtenerTiempo();

        auto duracion= duration_cast<duration<double>>(finaru-inicio);

        tiempo=duracion.count();
        cout<<i<<endl;

        nueva_prueba.clear();


        tiempos.push_back(tiempo);
        if(i==final)
            break;
    }
    ofstream times("Sorting_Results_2.txt",ios::out);
    for (int i = 0; i < tiempos.size(); ++i) {
        times<<tiempos[i]<<endl;
    }





}