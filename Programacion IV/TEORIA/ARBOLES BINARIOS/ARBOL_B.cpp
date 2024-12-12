#include "iostream"
using namespace std;
/**
 ARBOL B:
 VENTAJAS:
 AHORRO ACCESOS A LA MEMORIA SECUNDARIA
 MEMORIA SECUNDARIA:
 SSD, HDD, M2
 CARACTERISTICAS:
 * LA RAIZ TIENE AL MENOS 2 HIJOS Y AL MENOS CONTIENE UNA LLAVE
 * TODAS LAS HOJAS ESTAN AL MISMO NIVEL
 SI TODAS LAS HOJAS ESTAN AL MISMO NIVEL ES UN ARBOL PERFECTO
 * EN CADA NODO TODAS LAS LLAVES ESTAN ORDENADAS DE MENOR A MAYOR
 * Si M es el orden del Arbol, M es el n° max de hijos, se cumple que:
        - Cada nodo excepto la raiz (M/2 - 1) <= n° keys <= M
        - Cada nodo excepto la raiz M/2 <= n° hijos <= M
        SI M ES IMPAR M/2 ES LA FUNCION TECHO
 */
 // LLAVES SON LAS LISTAS LLENAS DE NODOS
 // NODOS INTERNOS: CUANDO TIENEN HIJOS

const int M = 4;

template<typename TK>
struct Node{
    TK* keys;
    Node** childre;
    int count;      // cantidad de hijos
    bool leaf;
    Node(){
        keys = new TK[M];
        for (int i = 0; i < M; ++i) {
            keys[i] = NULL;
        }
        leaf = true;
        count = 0;
        childre = new Node*[M+1];
        for (int i = 0; i < M; ++i) {
            childre[i] = nullptr;
        }
    }
};

template<typename T>
class Btree {
public:
    Node<T>* root;
    int t;
public:
    Btree(){
        root = nullptr;
        t =M;
    }
    void insert(T data){
        // si esta vacio, inicializamos el nodo
        if (root == nullptr){
            root = new Node<T>();
            root->keys[0] = data;
            root->count++;
        }
        else{
            int i = t;
            // Busco la posicion de la llave que no este nula
            while (!root->keys[i-1]){
                i--;
            }
            cout << i <<endl;
            root->keys[i] = data;
            while (i>0){
                if (root->keys[i-1] > root->keys[i]){
                    std::swap(root->keys[i-1] , root->keys[i]);
                }
                i--;
            }
        }
    }
};
int main(){
    auto arbol = new Btree<int>();
    arbol->insert(4);
    arbol->insert(5);
    arbol->insert(3);
    cout << arbol->root->keys[0] << endl;
    cout << arbol->root->keys[1] << endl;
    cout << arbol->root->keys[2] << endl;


    return 0;
}


template<typename T>
bool search(Node<T>* node,T key){
    int i = 0;
    while (i < node->count && key > node->childre[i]){
        i++;
    }
    if (i < node->count && key == node->keys[i]){
        return true;
    }
    if (node->leaf){        // si el nodo es hoja ya no puedo bajar, retornas false
        return false;
    }
    return search(node->childre[i],key);
}



/// Como insertamos
/// las inserciones se hacen siempre abajo
/// complejidad logM(n) + (M-1)*logM(n)
// Pero en memoria secundaria: no se considera (M-1) EL SPLIT
/// Y EN RAM SERIA logM(n) + ___logM(n)

/// EM AVL: log2(n) + log2(n)
/// PARA n grandes CONVIENE EL B-TREE
/// Para n pequeños CONVIENTE EL AVL

/// casos de INSERTAR
/// OBS: SIEMPRE LAS INSERCIONES SE HACEN EN LAS HOJAS
/**
 1er caso, cuando hay espacio
 2do caso, cuando insertas en una hoja que ya esta lleno
 Si no hay espacio la partimos
 */

/// BORRADO
/// CASO 0:


