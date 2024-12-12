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

const int M =3;

template<typename TK>
struct Node{
    TK* keys;           // array de keys
    Node** children;     //array de punteros a hijos
    int count;      // cantidad de hijos
    bool leaf;
    Node(){
        keys = new TK[M];
        for (int i = 0; i < M; ++i) {
            keys[i] = NULL;
        }
        leaf = true;
        count = 0;
        children = new Node*[M+1];
        for (int i = 0; i < M; ++i) {
            children[i] = nullptr;
        }
    }
    Node(const Node<TK>& other){

    }
    bool isfull(Node<TK> data){
        return data.count == M;
    }
    void insert_not_full(TK data){
        // Inicializar el índice como el índice más a la derecha
        int i = count-1;
        if (leaf){
            while (i >= 0 && keys[i] > data) {
                keys[i+1] = keys[i];
                i--;
            }

            // Insertar la nueva clave en la ubicación encontrada
            keys[i+1] = data;
            count++;
        }
        else{

        }
    }
    void split(){
        Node<TK>* temp = new Node<TK>;
        int i = 0;
        temp->insert(this->keys[1]);
        *this = *temp;
//        root->childre

    }
    string to_string() {
        string result;
        if (leaf) {
            for (int i = 0; i < count; ++i) {
                result += std::to_string(keys[i]);
                if (i != count - 1)
                    result += ",";
            }
        } else {
            for (int i = 0; i < count; ++i) {
                result += children[i]->to_string() + ",";
                result += std::to_string(keys[i]) + ",";
                if (i != count - 1)
                    result += ",";
            }
            result += children[count]->to_string();
        }
        return result;
    }
};

template<typename T>
class Btree {
public:
    Node<T>* root;
    int t;
    void split(const Node<T>* raiz){
        auto* temp = new Node<T>;
        int i = 0;
        insert(temp,raiz->keys[1]);
//        delete root;
//        root = temp;
//        root->childre

    }
    void insert(Node<T>* raiz,T data){
        // si esta vacio, inicializamos el nodo
        if (raiz->count == 0){
            raiz->keys[0] = data;
            raiz->count++;
        }
        else{
            // SI RAIZ ESTA LLENA
            if (root->count == t-1){


            }
            // SI NO ESTA LLENA
            else{
                root->insert_not_full(data);
            }
        }
    }
public:
    Btree(){
        root = new Node<T>;
        t =M;
    }
    void insert(T data){
        insert(root,data);
    }
    void split(){
        split(root);
    }
    void display(){
        cout << root->to_string() << endl;
    }
    bool isfull(){
        return root->count == M;
    }
};
int main(){


    auto arbol = new Btree<int>();
    arbol->insert(4);
    arbol->insert(5);
    arbol->insert(3);
    cout << endl;
    cout << arbol->root->keys[0] << endl;
    cout << arbol->root->keys[1] << endl;
    cout << arbol->root->keys[2] << endl;
//    cout << "count:" << arbol->root->count << endl;
//    arbol->display();
//    arbol->split();
//    arbol->display();

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


