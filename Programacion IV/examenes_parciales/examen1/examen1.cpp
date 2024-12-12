#include "iostream"
#include "queue"

/**
 * C.	(2 puntos) Dado un árbol binario de búsqueda, se le pide diseñar un algoritmo en C++ que imprima los nodos extremos de cada nivel:
*/

using namespace std;
template<typename T>
class BSTree{
private:
    struct NodePT{
        T data;
        NodePT* left;
        NodePT* right;
    };
    NodePT* root; // nodo raiz
    bool find(NodePT* nodo, T value){
        if (nodo == nullptr){
            return false;
        }
        else if (value < nodo->data){
            find(nodo->left,value);
        }
        else if (value > nodo->data){
            find(nodo->right,value);
        }
        else{
            return true;
        }
    }
    void insert(NodePT* &nodo, T value){
        if (nodo == nullptr){
            auto nuevo = new NodePT();
            nuevo->data = value;
            nuevo->left = nullptr;
            nuevo->right = nullptr;
            nodo = nuevo;
        }
        else if (value < nodo->data){
            insert(nodo->left,value);
        }
        else if (value > nodo->data) {
            insert(nodo->right, value);
        }
    }
    string displayPostOrder(NodePT* nodo){
        if (nodo == nullptr){
            return "";
        }
        string result = to_string(nodo->data);
        if (nodo->left == nullptr && nodo->right == nullptr){
            return result;
        }
        return displayPostOrder(nodo->left) + displayPostOrder(nodo->right) + result;
    }
    string displayInOrder(NodePT* nodo){
        if (nodo == nullptr){
            return "";
        }
        string result = to_string(nodo->data);
        if (nodo->left == nullptr && nodo->right == nullptr){
            return result;
        }
        return displayInOrder(nodo->left) + result + displayInOrder(nodo->right)  ;
    }
    string displayPreOrder(NodePT* nodo){
        if (nodo == nullptr){
            return "";
        }
        string result = to_string(nodo->data) + " ";
        if (nodo->left == nullptr && nodo->right == nullptr){
            return result;
        }
        return result + displayPreOrder(nodo->left) + displayPreOrder(nodo->right)  ;
    }
    void display_extremos(NodePT* raiz){
        if (raiz == nullptr)
            return;
        queue<NodePT*> cola;
        cola.push(raiz);
        while (!cola.empty()) {
            int levelSize = cola.size();
            for (int i = 0; i < levelSize; i++) {
                NodePT* currentNode = cola.front();
                cola.pop();
                if (i == 0 || i == levelSize - 1){
                    cout << currentNode->data << " ";
                }
                if (currentNode->left)
                    cola.push(currentNode->left);
                if (currentNode->right)
                    cola.push(currentNode->right);
            }
            cout << endl;

        }
    }
    void display_BFS_pornivel(NodePT* raiz){
        if (raiz == nullptr)
            return;
        queue<NodePT*> cola;
        cola.push(raiz);
        while (!cola.empty()) {
            int levelSize = cola.size();
            for (int i = 0; i < levelSize; i++) {
                NodePT* currentNode = cola.front();
                cola.pop();
                cout << currentNode->data << " ";
                if (currentNode->left)
                    cola.push(currentNode->left);
                if (currentNode->right)
                    cola.push(currentNode->right);
            }
            cout << endl;

        }
    }
public:
    void remove(int pos){

    }
    // INICIALIZAMOS LA RAIZ EN NULLPTR
    BSTree(){
        root = nullptr;
    }
    void display_BFS_pornivel(){
        display_BFS_pornivel(root);
    }
    // IMPLEMENTAMOS LA BUSQUEDA
    void display_extremos(){
        display_extremos(root);
    }
    bool find(T value){
        return find(root,value);
    }
    void insert(T value){
        insert(root,value);
    }
    string displayPostOrder(){
        string result = displayPostOrder(root);
        return result;
    }
    string displayInOrder(){
        string result = displayInOrder(root);
        return result;
    }
    string displayPreOrder(){
        string result = displayPreOrder(root);
        return result;
    }
    /// COMO HARIAN EL REMOVER UN ELEMENTO
    // CASO 1: CUANDO EL NODO A ELIMINAR ES UNA HOJA
    // CASO 2: CUANDO EL NODO A ELIMINAR TIENE UN SOLO HIJO --> EL HIJO REEMPLAZA A DICHO NODO (DESCOLGAMOS EL NODO A ELIMINAR Y COLGAMOS EL HIJO)
    // CASO 3: CUANDO EL NODO A ELIMINAR TIENE DOS HIJOS --> NO PODEMOS HACERLO DIRECTAMENTE (VOY A HACER UN SWAP CON SU SUCESOR O PREDECESOR)
    //      AL SUCESOR DE DICHO NODO HAREMOS SWAP CON EL NODO A ELIMINAR. Y LUEGO
};

int main(){
    auto *bstree = new BSTree<int>();
    bstree->insert(8);
    bstree->insert(3);
    bstree->insert(10);
    bstree->insert(1);
    bstree->insert(6);
    bstree->insert(14);
    bstree->insert(4);
    bstree->insert(7);
    bstree->insert(13);
    bstree->display_extremos();
    return 0;
}