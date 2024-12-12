#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Arista{
    char inicio;
    char fin;
    int peso;
    Arista(char _inicio, char _fin, int _peso){
        inicio = _inicio;
        fin = _fin;
        peso = _peso;
    }
    /// para poder utilizar el sort en dicha clase, necesito sobrecargar el operador "<"
    /// para que lo puedo ordenar dependiendo de los pesos:
    bool operator<(const Arista& arista) const{
        /// si lo pongo "<" ordenara de manera ascendente
        /// si lo pongo ">" ordenara de manera descendente
        return peso < arista.peso;
    }
};

class Grafo{
private:
    vector<Arista> G;
    vector<Arista> AEM;

    /// Mapa donde la clave sera un vertice, y el valor el padre del vertice.
    /// ""Un vertice solo puede tener un padre""
    map<char, char> padre;
public:
    void insertar_arista(char inicio, char fin, int peso){
        /// Debe inserter una Arista en el grafo, y además inicializar cada vértice unido a sí mismo.
        /// Por eso al principio cada vertice sera padre de si mismo. osea sera padre e hijo al mismo tiempo
        G.push_back(Arista(inicio,fin,peso));
        padre[inicio] = inicio;
        padre[fin] = fin;
    }
    char encontrar_padre(char vertice){
        /// Debe de retornar el padre de vertice. Un vértice es padre si
        /// vertice = padre[vertice].  Si no se cumple esta expresión, retornar       encontrar_padre(padre[vertice]).

        /// Si el vertice es igual al padre de dicho vertice, entonces retorna vertice
        if (vertice == padre[vertice])
            return vertice;
        else
            /// Caso contrario sigue ejecutando dicha funcion hasta encontrarlo
            return encontrar_padre(padre[vertice]);
    }
    void unir(char vertice1, char vertice2){
        if (padre[vertice1]==vertice1)
            padre[vertice1] = vertice2;
        else
            padre[vertice2] = vertice1;
    }
    void mostrar_padres(){
        /// Mostrar todos los vértices y sus padres respectivos usando encontrar_padre.

        cout << "Vertices: ";
        for(auto it=padre.begin();it!=padre.end(); it++)
            cout << (*it).first << " ";
        cout<<endl;
        cout << "Padres  : ";
        for(auto it=padre.begin();it!=padre.end(); it++)
            cout << encontrar_padre((*it).first) << " ";
        cout<<endl;
    }

    void kruskal(){
        char padre1, padre2;
        sort(G.begin(), G.end());
        for (auto it=G.begin(); it!=G.end(); it++){
            padre1 = encontrar_padre((*it).inicio);
            padre2 = encontrar_padre((*it).fin);
            /// Primero debe detectar si los dos verties tienen el mismo padre (Bucle). Luego debe de asignar vertice2 como el padre de vertice1.

            /// Verifico que el padre de dicho vertice1 es igual al padre de dicho vertice2
            if (padre1 != padre2){
                AEM.push_back(*it);
                unir((*it).inicio, (*it).fin);
            }
        }
    }

    void printAEM(){
        for (auto it=AEM.begin(); it!=AEM.end(); it++){
            cout << (*it).inicio << " - ";
            cout << (*it).fin << endl;
        }
    }
};


int main(){
    Grafo G;
    G.insertar_arista('A','B',5);
    G.insertar_arista('A','C',7);
    G.insertar_arista('B','C',9);
    G.insertar_arista('B','E',15);
    G.insertar_arista('B','F',6);
    G.insertar_arista('C','D',8);
    G.insertar_arista('C','E',7);
    G.insertar_arista('D','E',5);
    G.insertar_arista('E','F',8);
    G.insertar_arista('E','G',9);
    G.insertar_arista('F','G',11);
    /*
    G.insertar_arista('A','B',5);
    G.insertar_arista('B','C',3);
    G.insertar_arista('B','E',2);
    G.insertar_arista('B','D',5);
    G.insertar_arista('C','E',1);
    G.insertar_arista('D','A',4);
    G.insertar_arista('D','E',2);
    G.insertar_arista('D','F',6);
    G.insertar_arista('E','F',4);
    G.insertar_arista('E','G',6);
    G.insertar_arista('F','G',2);
    */
    G.kruskal();
    G.printAEM();

    return 0;
}