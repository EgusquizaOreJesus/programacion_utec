#include "iostream"
#include "vector"

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
//            cout << "insert value < node"<<endl;
            insert(nodo->left,value);
        }
        else {
//            cout << "insert value > node"<<endl;
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
            return result + " ";
        }
        return displayInOrder(nodo->left) + result +" "+ displayInOrder(nodo->right)  ;
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
    bool isHoja(NodePT* nodo){
        return (nodo->left == nullptr && nodo->right == nullptr);
    }
    NodePT* sucesor(NodePT* nodo){
        NodePT* actual = nodo;
        while (actual->left != nullptr)
            actual = actual->left;
        return actual;
    }
    void remove(NodePT* &nodo, T value){
        if (nodo->data == value){
            cout << "nodo encontrado:" << nodo->data << endl;
            if (isHoja(nodo)){
                nodo = nullptr;
            }
            else if (nodo->left == nullptr && nodo->right != nullptr){
                NodePT* temp = nodo->right;
                nodo->right = nullptr;
                nodo = temp;
            }
            else if (nodo->left != nullptr && nodo->right == nullptr){
                NodePT* temp = nodo->left;
                nodo->left = nullptr;
                nodo = temp;
            }
            else{
                NodePT* temp2 = nodo;
                temp2 = temp2->right;
                // buscamos el sucesor del nodo
                while (temp2->left!= nullptr){
                    temp2 = temp2->left;
                }
                std::swap(nodo->data,temp2->data);
                remove(nodo->right,temp2->data);
            }
            return;
        }
        else if (value < nodo->data){
            remove(nodo->left,value);
        }
        else if (value > nodo->data) {
            remove(nodo->right, value);
        }
        update_height(nodo);
        rotacion(nodo);

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
    void remove(T value){
        remove(root,value);
    }
    // rotacion hacia la derecha
    void rota_left(NodePT* &P){
        NodePT* Q = P->right;
        P->right = Q->left; // CON ESTO DESCUELGO EL VALOR DE P->RIGHT
        Q->left = P;        // PARA QUE CUANDO CUELGUE P NO SE CUELGUE CON SU VALOR ANTIGUO DE P->RIGHT
        update_height(P);
        update_height(Q);
        P = Q;
    }
    void rota_right(NodePT* &P){
        NodePT* Q = P->left;
        P->left = Q->right;     // DESCOLGAMOS EL VALOR DE P->left
        Q->right = P;           // colgamos Q->right con P, ya habiendo actulizado p->left
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
//        cout << "nodo:" << P->data << endl;
//        cout <<"altura del nodo: " <<P->height << endl;
        int hb = factor_balanceo(P);
//        cout << "factor de balanceo:" << hb << endl;
        // CASO 1: ROTACION SIMPLE
        if (hb >= 2){

            if (factor_balanceo(P->left) < 0){
//                cout << "condicion 2" << endl;
                rota_left(P->left);
            }
            rota_right(P);
        }

        if (hb <= -2){              // NODO CRITICO, SOBRECARGADO DERECHA
                if (factor_balanceo(P->right) > 0){
//                cout << "condicion 2-1" << endl;

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
    bstree->insert(2);
    bstree->insert(1);
    bstree->insert(15);
    bstree->insert(9);
    bstree->insert(10);
    bstree->remove(9);
    cout << bstree->displayInOrder() << endl;
    bstree->remove(2);
    cout << bstree->displayInOrder() << endl;

    bstree->remove(3);
    cout << bstree->displayInOrder() << endl;
    bstree->remove(1);
    cout << bstree->displayInOrder() << endl;
    bstree->remove(15);
    cout << bstree->displayInOrder() << endl;
    bstree->remove(10);
    cout << bstree->displayInOrder() << endl;
    bstree->insert(19);
    bstree->insert(22);
    bstree->insert(20);

    cout << bstree->displayInOrder() << endl;

    cout << bstree->root->data << " "<<bstree->root->left->data << " " << bstree->root->right->data << endl;
 }

