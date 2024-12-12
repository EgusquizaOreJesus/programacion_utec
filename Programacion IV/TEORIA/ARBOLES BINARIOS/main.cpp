#include <iostream>
#include "stack"

/**
Arboles tipos de nodo
 Raiz: El primer nodo de un arbol
 Padre: Todo nodo que tiene al menos un hijo
 Hijo: Todo nodo que tiene un padre
 Hermano: Nodos con padre comun dentro de la estuctura
 Hoja: No tienen hijos y se encuentran en los extremos de la estructura

 ARBOL BINARIO:
 Es un arbol donde cada nodo solo puede tener 2 hijos como MAXIMO
 ARBOL BINARIO COMPLETO:
 Es un arbol que tiene lleno todo los niveles,
 Osea todos los niveles tienen dos hijos
 se puede dar una excepcion con el ultimo nivel
 Pero si tiene que estar de izquiera a derecha sus elementos, si eso no cumple NO ESTA COMPLETO
 ARBOL BINARIO LLENO
 Es aquel que cada nodo tiene 0 o dos hijos
 ARBOL BINARIO PERFECTO
 Todas las hojas estan al mismo nivel
 ARBOL BINARIO BALANCEADO
 Antes que eso que es la altura --> La altura se define como el camino mas largo del nodo hacia la ultima hoja
 Partiremos desde cero
 Un arbol es balanceado cuando la diferencia de la altura del hijo derecho e izquierdo no excede a 1
 EL BALANCEO TIENE QUE DARSE PARA CADA NODO HIJO

 obs:   TODO ARBOL COMPLETO ES BALANCEADO --> SI
        TODO ARBOL BALANCEADO ES COMPLETO --> NO NECESARIAMENTE
        TODO ARBOL PERFECTO SERA BALANCEADO --> SI
        TODO ARBOL PERFECTO SERA COMPLETO --> NO
 */
/**
Arbol binario de busqueda
 Debe cumplir que:
Para cualquier nodo, todo lo que esta a la izquierda de ese nodo es menor y todo lo de la derecha es mayor
 */

/**
IMPLEMENTACION DE UN ARBOL BINARIO DE BUSQUEDA
 SOLAMENTE NECESITO LA REFERENCIA DEL PRIMER NODO, EL NODO RAIZ PARA ASI RECORRER TODO
 LO UNICO QUE NECESITO TENER ES LA RAIZ, CON LA RAIZ YO RECORRO TODO EL NODO
 */
 /// NO OLVIDAR LA PROPIEDAD A LA IZQUIERA LOS MENORES A LA DERECHA LOS MAYORES

 /// OBS: Un arbol tambien se puede utilizar en diccionarios, pondriamos key - value como atributos del nodo
 /// cOMO IMPLEMENTAMOS LA BUSQUEDA:
 /**
// UN ARBOL SUPER DESBALANCEADO, ES CUANDO INSERTAS UN ARRAY ORDENADO
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
    string displayDFS(NodePT* nodo){
        stack<NodePT*> stack_;

    }
public:
    // INICIALIZAMOS LA RAIZ EN NULLPTR
    BSTree(){
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
    /// COMO HARIAN EL REMOVER UN ELEMENTO
    // CASO 1: CUANDO EL NODO A ELIMINAR ES UNA HOJA
    // CASO 2: CUANDO EL NODO A ELIMINAR TIENE UN SOLO HIJO --> EL HIJO REEMPLAZA A DICHO NODO (DESCOLGAMOS EL NODO A ELIMINAR Y COLGAMOS EL HIJO)
    // CASO 3: CUANDO EL NODO A ELIMINAR TIENE DOS HIJOS --> NO PODEMOS HACERLO DIRECTAMENTE (VOY A HACER UN SWAP CON SU SUCESOR O PREDECESOR)
    //      AL SUCESOR DE DICHO NODO HAREMOS SWAP CON EL NODO A ELIMINAR. Y LUEGO
};


int main() {
    auto *bstree = new BSTree<char>();
    bstree->insert(8);
    bstree->insert(3);
    bstree->insert(1);
    bstree->insert(6);
    bstree->insert(4);
    bstree->insert(7);
    bstree->insert(10);
    bstree->insert(14);
    bstree->insert(13);

    cout << bstree->displayPreOrder();
    return 0;
}
