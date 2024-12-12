#include "iostream"

///                         BST: arbol binario de busqueda

/// Cada clave en el árbol binario de búsqueda debe ser insertado de modo que cumpla la siguiente propiedad:
/// Si n es un nodo del árbol binario, y x es el nodo hijo izquierdo de n, entonces
///                                x.key ﹤ n.key
/// Si y es el nodo hijo derecho de n, entonces:
///                                y.key ≥ n.key

/// Esta propiedad especial de un árbol binario de búsqueda permite imprimir todas las claves en orden ascendente/descendente.
using namespace std;
struct Nodo{
    int key;        // Representa la clave del nodo
    Nodo* left{};     // Este representa el nodo izquierdo (hijo) del nodo actual
    Nodo* right{};    // Este representa el nodo derecho (hijo) del nodo actual
    Nodo(int x){key = x;}
};

class BST{
    Nodo* root;
public:
    BST(){
        root = NULL;
    }
    void insert(int key, Nodo* leaf){
        /// Primer caso que debe cumplir si quiere insertarse a la izquierda y ser nodo hijo de el nodo anterior "n"
        /// Debe cumplir que dicha key a insertar debe ser menor al key del padre "n" --> x.key < n.key
        if (key < leaf->key){
            if (leaf->left == NULL){
                leaf->left = new Nodo(key);
            }
            else{
                insert(key, leaf->left);
            }
        }
        /// El otro caso que debe cumplir es que si quiere insertarse a la derecha y ser nodo hijo derecho de el anterior nodo "n"
        /// Debe cumplir que dicha key a insertar deber ser mayor o igual al key del padre "n" ---> y.key >= n.key
        else{
            if (leaf->right == NULL){
                leaf->right = new Nodo(key);
            }
            else{
                insert(key,leaf->right);
            }
        }
    }
    void insert(int key){
        if (root == NULL){
            root = new Nodo(key);
        }
        else{
            insert(key,root);
        }
    }
    void print_tree(){
        cout << root->left->key << endl;
        cout << root->key << endl;
        cout << root->right->key << endl;
    }
};
int main() {
    BST bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);
    bt.print_tree();

}