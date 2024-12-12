#include "iostream"

using namespace std;
/// CADA NODO POSEE ATRIBUTOS LEFT Y RIGHT, ADEMAS CADA NODO TIENE UNA CLAVE (KEY)
/// Los nodos pueden tener hijos y padres, y los que no tienen se les asigna NULL


struct Nodo{
    int key;        // Representa la clave del nodo
    Nodo* left;     // Este representa el nodo izquierdo (hijo) del nodo actual
    Nodo* right;    // Este representa el nodo derecho (hijo) del nodo actual
    Nodo(int x){key = x;}
};

int main(){
    /// Creamos el nodo raiz que sera Root
    Nodo* root = new Nodo(5);
    /// Sus nodos hijos que seran left y right
    root->left = new Nodo(4);
    root->right = new Nodo(6);

    cout << root->left->key << endl;
    cout << root->key << endl;
    cout << root->right->key << endl;




}