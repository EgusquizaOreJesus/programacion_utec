#include "iostream"
#include "vector"
/**
ARBOL AVL
calcule el factor de equilibrio

 Es critico cuando es mayor o igual a -2
 haces doble rotacion
 cuando el ancestro y el hijo tienen signos diferentes

*/

/**
BUSQUEDA POR RANGE
 es busqueda por range
 1. para buscar una opcion seria por inorder y luego filtrar, pero seria poco eficiente para grandes numeros de data --> O(n)
 2. Usando los sucesores:
 ejem: range(330,350) --> buscamos el sucesor de 330 y asi sucesivamente
 complejidad k*log(n) --> ventajas para k pequeños
 3. Usar stack: --> log(n) + k  --> k es el rango

 */
using namespace std;
template<typename T>
class AVL{
public:
    struct NodePT{
        T data;
        NodePT* left;
        NodePT* right;
        int height;
        NodePT(): left(nullptr), right(nullptr), height(0) {}
        NodePT(T value) : data(value), left(nullptr), right(nullptr), height(0) {}
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
            nodo = new NodePT(value);
        }
        else if (value < nodo->data){
            insert(nodo->left,value);

        }
        else if (value > nodo->data) {
            insert(nodo->right, value);
        }
        /// REGRESO DE LA RECURSIVIDAD
        update_height(nodo);
        rotacion(nodo);
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
public:
    // INICIALIZAMOS LA RAIZ EN NULLPTR
    AVL(){
        root = nullptr;
    }
    // IMPLEMENTAMOS LA BUSQUEDA
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

    // rotacion hacia la derecha
    void rota_left(NodePT* &P){
        NodePT* Q = P->right;
        P->right = Q->left;
        Q->left = P;
        update_height(P);
        update_height(Q);
        P = Q;
    }
    void rota_right(NodePT* &P){
        NodePT* Q = P->right;
        P->left = Q->right;
        Q->right = P;
        update_height(P);
        update_height(Q);
        P= Q;
    }
    void range_search(NodePT* node, vector<T> &result, T begin, T end){
        if (node->data >= begin){       // bajas por la derecha}
            range_search(node->left,result,begin,end);
        }
        if (node->data <= end){
            range_search(node->right,result,begin,end);
        }
    }
    int height(NodePT* node){
        if (node == nullptr) return -1;
        else return node->height;
    }
    int factor_balanceo(NodePT* P){
        return height(P->left) - height(P->right);
    }
    void update_height(NodePT* &node){
        node->height = max(height(node->left), height(node->right)) + 1;
    }
    void rotacion(NodePT* &P){      // NODO CRITICO, SOBRECARGADO IZQUIERDA
        int hb = factor_balanceo(P);
        if (hb >= 2){
            if (factor_balanceo(P->left) < 0){
                rota_left(P->left);
            }
            rota_right(P);
        }
        if (hb <= -2){              // NODO CRITICO, SOBRECARGADO DERECHA
            if (factor_balanceo(P->right) > 0){
                rota_right(P->right);
            }
            rota_left(P);
        }
    }

    /// COMO HARIAN EL REMOVER UN ELEMENTO
    // CASO 1: CUANDO EL NODO A ELIMINAR ES UNA HOJA
    // CASO 2: CUANDO EL NODO A ELIMINAR TIENE UN SOLO HIJO --> EL HIJO REEMPLAZA A DICHO NODO (DESCOLGAMOS EL NODO A ELIMINAR Y COLGAMOS EL HIJO)
    // CASO 3: CUANDO EL NODO A ELIMINAR TIENE DOS HIJOS --> NO PODEMOS HACERLO DIRECTAMENTE (VOY A HACER UN SWAP CON SU SUCESOR O PREDECESOR)
    //      AL SUCESOR DE DICHO NODO HAREMOS SWAP CON EL NODO A ELIMINAR. Y LUEGO
};
int main(){
    auto *bstree = new AVL<int>();
    bstree->insert(8);
    bstree->insert(3);
    bstree->insert(5);





}

