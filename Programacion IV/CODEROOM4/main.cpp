#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <map>
#include <unistd.h>
#include <fstream>
using namespace std;
const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789   ";
vector<int> intuitivo(string big_A, string mini_b) {


    int i = 0;

    vector<int> pos;
    int n = big_A.size();
    int m = mini_b.size();
    bool finded= false;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (big_A[i + j] != mini_b[j])
            {
                break;
            }
        }

        if (j == m)
            pos.push_back(i);
    }


    return pos;
}
vector<int> calcularSaltos(const string& patron) {
    int m = patron.size();
    vector<int> saltos(256, m);

    for (int i = 0; i < m - 1; i++) {
        saltos[patron[i]] = m - 1 - i;
    }

    return saltos;
}
vector<int> BoyerMoore(const string& texto, const string& patron) {
    vector<int> pos;
    int n = texto.length();
    int m = patron.length();
    vector<int> saltos = calcularSaltos(patron);

    int i = m - 1;
    while (i < n) {
        int j = m - 1;
        while (j >= 0 && texto[i] == patron[j]) {
            i--;
            j--;
        }

        if (j == -1) {
            pos.push_back(i+1);
            i=i+1;
        }

        i += max(saltos[texto[i]], m - 1 - j);
    }

    return pos;
}
string generarTexto(size_t N){
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() %  alfabeto.size()];
    return resultado;
}

vector<int> testInocente(string Texto, string Patron)
{
    auto start = std::chrono::steady_clock::now();


    vector<int> result= intuitivo(Texto,Patron);

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Inocente time in microseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " ms" << endl;
    auto time=chrono::duration_cast<chrono::microseconds>(end - start).count();
    fstream archivar_time("Intuitivo.txt",ios::app);
    archivar_time<<time<<endl;
    return result;
}

vector<int> testBoyerMoore(string Texto, string Patron)
{
    auto start = std::chrono::steady_clock::now();


    vector<int> result;
    result= BoyerMoore(Texto,Patron);

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "BoyerMoore time in microseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " ms" << endl;
    auto time=chrono::duration_cast<chrono::microseconds>(end - start).count();
    fstream archivar_time("Boyer.txt",ios::app);
    archivar_time<<time<<endl;


    return result;
}

void verificarResultado(vector<int> result1, vector<int> result2)
{
    if(result1.size() != result2.size())
        cerr <<"Error!! el resultado no es el mismo\n";
    for(int i=0;i<result1.size();i++)
        if(result1[i] != result2[i])
            cerr <<"Error!! el resultado no es el mismo\n";
}

int main()
{
    srand(time(NULL));

    vector<size_t> N{100,1000,10000,100000,1000000};
    int m = 10;

//    string Texto = "AABAACAADAABAABA";//GCGATGCCTA
//    string Patron = "AABA";//TATATG
    for(auto v:N)
    {
        string Texto = generarTexto(v);
        string Patron = generarTexto(m);
        vector<int> result1 = testInocente(Texto, Patron);
        vector<int> result2 = testBoyerMoore(Texto, Patron);
        verificarResultado(result1, result2);
    }


    return 0;
}

