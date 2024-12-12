#include "iostream"
#include "vector"
#include "map"

using namespace std;

struct Arista{
    char inicio;
    char final;
    int peso;
    Arista(char _in, char _fi, int _pe):inicio(_in),final(_fi),peso(_pe){};

    bool operator<(const Arista& arista) const{
        return peso < arista.peso;
    }


};

class Grafo{

    vector<Arista> G;
    /// Mapa donde la clave sera un vertice, y el valor el padre del vertice. ""Un vertice solo puede tener un padre""
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
        /// Primero debe detectar si los dos verties tienen el mismo padre (Bucle). Luego debe de asignar vertice2 como el padre de vertice1.

        /// Verifico que el padre de dicho vertice1 es igual al padre de dicho vertice2
        if (encontrar_padre(vertice1) == encontrar_padre(vertice2))
            cout << "Se formará un bucle" << endl;
        else{
            if (padre[vertice1]==vertice1)
                padre[vertice1] = vertice2;
            else
                padre[vertice2] = vertice1;
        }
    }
    void mostrar_padres(){
        /// Mostrar todos los vértices y sus padres respectivos usando encontrar_padre.

        cout << "Vertices: ";
        for(auto it=padre.begin();it!=padre.end(); it++)
            cout << (*it).first << " ";         // key -> vertice
        cout<<endl;
        cout << "Padres  : ";
        for(auto it=padre.begin();it!=padre.end(); it++)
            cout << encontrar_padre((*it).first) << " ";
        cout<<endl;
    }

};
int main(){
    Grafo G;
    G.insertar_arista('A','B',5);
    G.insertar_arista('B','C',3);

    G.mostrar_padres();
    cout << "Uniendo A y B" << endl;
    G.unir('A','B');
    G.mostrar_padres();

    cout << "Uniendo B y C" << endl;
    G.unir('B','C');
    G.mostrar_padres();

    cout << "Uniendo A y C" << endl;
    G.unir('A','C');

    return 0;
}