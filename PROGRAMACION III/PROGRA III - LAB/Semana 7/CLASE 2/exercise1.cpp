#include "iostream"
#include "vector"

using namespace std;

struct Arista{
    char inicio;
    char final;
    int peso;
    Arista(char _in, char _fi, int _pe):inicio(_in),final(_fi),peso(_pe){};

    /// para poder utilizar el sort en dicha clase, necesito sobrecargar el operador "<"
    /// para que lo puedo ordenar dependiendo de los pesos:
    bool operator<(const Arista& arista) const{
        /// si lo pongo "<" ordenara de manera ascendente
        /// si lo pongo ">" ordenara de manera descendente
        return peso < arista.peso;
    }


};

int main(){
    vector<Arista> aristas;
    aristas.push_back(Arista('A','B',5));
    aristas.push_back(Arista('B','C',3));
    aristas.push_back(Arista('B','E',2));
    aristas.push_back(Arista('B','D',5));
    aristas.push_back(Arista('C','E',1));
    aristas.push_back(Arista('D','A',4));
    aristas.push_back(Arista('D','E',2));
    aristas.push_back(Arista('D','F',6));
    aristas.push_back(Arista('E','F',4));
    aristas.push_back(Arista('E','G',6));
    aristas.push_back(Arista('F','G',2));

    sort(aristas.begin(), aristas.end());
    for_each(aristas.begin(), aristas.end(), [](Arista a){cout << a.peso << endl;});

    return 0;
}