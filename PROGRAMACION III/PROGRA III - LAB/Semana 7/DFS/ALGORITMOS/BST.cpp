#include <iostream>
///                         BST: arbol binario de busqueda

/// Cada clave en el árbol binario de búsqueda debe ser insertado de modo que cumpla la siguiente propiedad:
/// Si n es un nodo del árbol binario, y x es el nodo hijo izquierdo de n, entonces
///                                x.key ﹤ n.key
/// Si y es el nodo hijo derecho de n, entonces:
///                                y.key ≥ n.key

/// Esta propiedad especial de un árbol binario de búsqueda permite imprimir todas las claves en orden ascendente/descendente.
using namespace std;
struct Nodo{
    int key;
    Nodo* left;
    Nodo* right;
};

class BST{
private:
    Nodo* root;
public:
    BST(){
        root=NULL;
    }
    void insert(int x, Nodo* leaf){
        if (x < leaf->key){
            if (leaf->left==NULL){
                leaf->left=new Nodo;
                /// Al asignarle un nodo
                /// al key le asigno la clave
                /// y a sus respectivos hijos que por ahora estan vacios les asigno NULL
                leaf->left->key=x;
                leaf->left->left=NULL;
                leaf->left->right=NULL;
            }
            else{
                insert(x, leaf->left);
            }
        }
        else{
            if (leaf->right==NULL){
                leaf->right=new Nodo;
                /// Al asignarle un nodo
                /// al key le asigno la clave
                /// y a sus respectivos hijos que por ahora estan vacios les asigno NULL
                leaf->right->key=x;
                leaf->right->left=NULL;
                leaf->right->right=NULL;
            }
            else{
                insert(x, leaf->right);
            }
        }
    }
    void insert(int x){
        if (root==NULL){
            root = new Nodo;
            /// Forma optima de asignar
            root->key=x;
            root->left=NULL;
            root->right=NULL;
        }
        else{
            insert(x, root);
        }
    }
    /// FUNCION PARA PRINTEAR EL ARBOL BST
    void in_order_tree_walk(Nodo* nodo){
        if (nodo != NULL){
            in_order_tree_walk(nodo->left);
            cout << nodo->key << " ";
            in_order_tree_walk(nodo->right);
        }
    }
    void print_tree(){
        in_order_tree_walk(root);
        cout << endl;
    }
};
int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);
    bst.insert(2);
    bst.insert(3);
    bst.insert(1);
    bst.print_tree();
}