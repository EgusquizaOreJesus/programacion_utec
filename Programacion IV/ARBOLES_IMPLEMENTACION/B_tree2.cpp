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

const int M =3;     // max de hijos

template<typename TK>
struct Node{
    TK* keys;           // array de keys
    Node** children;     //array de punteros a hijos
    int count;      // cantidad de hijos
    bool leaf;      // es hoja
    Node(){
        keys = new TK[M];
        for (int i = 0; i < M; ++i) {
            keys[i] = NULL;
        }
        leaf = true;
        count = 0;
        children = new Node*[M+1];
        for (int i = 0; i < M+1; ++i) {
            children[i] = nullptr;
        }
    }
    Node(const Node<TK>& other){

    }
    bool isfull(Node<TK> data){
        return data.count == M-1;
    }

};

template<typename T>
class Btree {
public:
    Node<T>* root = nullptr;
    // key es el valor que estamos insertando en dicho nodo
    void insert(const T& key)
    {
        insert(root,root, key);
    }
    void bfs(){
        bfs(root);
    }
    void print_Nodo(Node<T>* node){
        for (int i = 0; i < node->count; ++i) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
    }

private:
    void insert(Node<T>*& node,Node<T>*& parent, const T& key){
        if (node == nullptr){
            node = new Node<T>;
            node->keys[0] = key;
            node->count = 1;
            return;
        }
        if (is_leaf(node)) {
            insertNonFull(node, key);
        }
        // buscar el hijo donde se insertara la clave
        else{
            int i = node->count - 1;
            while (i >= 0 && key < node->keys[i]){
                i--;
            }
            i++;
            insert(node->children[i],node,key);
        }
        cout << "vuelta a insert" << endl;
        cout << "print nodo actual" << endl;
        cout << "size: " << node->count << endl;
        for (int i = 0; i < node->count; ++i) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
        cout << "parent" << endl;
        for (int i = 0; i < parent->count; ++i) {
            cout << parent->keys[i] << " ";
        }
        cout << endl;
        if (node->count == M){
            splitchild(node,parent);
        }
    }
    void splitchild(Node<T>*& child, Node<T>*& parent){
        if( parent == child){
            cout << "split root" << endl;
            // root
            cout << "parent" << endl;
            print_Nodo(parent);
            cout << "child" << endl;
            print_Nodo(child);
            cout << "child childs" << endl;
            if (child->children[0] != nullptr){
                print_Nodo(child->children[0]);
                print_Nodo(child->children[1]);
                print_Nodo(child->children[2]);
                print_Nodo(child->children[3]);
            }
            T middle_key = child->keys[M/2];
            auto new_root = new Node<T>;
            new_root->keys[0] = middle_key;
            new_root->count = 1;
            new_root->leaf = false;
            for (int i = 0; i < M; ++i) {
                cout << "i: " << child->keys[i] << endl;
            }
            // recorrer el child
            auto new_child_left = new Node<T>;
            auto new_child_right = new Node<T>;
            new_child_left->leaf = child->leaf;
            new_child_right->leaf = child->leaf;
            new_child_left->count = M/2;
            new_child_right->count = M - M/2 - 1;
            // copio las claves
            for (int i = 0; i < M/2; ++i) {
                new_child_left->keys[i] = child->keys[i];
            }
            int iter = 0;
            for (int i = M/2+1; i < M; ++i) {
                new_child_right->keys[iter] = child->keys[i];
                iter++;
            }
            if (!child->leaf){
                for (int i = 0; i < M/2+1; ++i) {
                    new_child_left->children[i] = child->children[i];
                }
                iter = 0;
                for (int i = M/2+1; i < M+1; ++i) {
                    new_child_right->children[iter] = child->children[i];
                    iter++;
                }
            }
            print_Nodo(new_child_left);
            print_Nodo(new_child_right);
            // añado los hijos
            new_root->children[0] = new_child_left;
            new_root->children[1] = new_child_right;
            root = new_root;
        }else{
            cout << "split child" << endl;
            T middle_key = child->keys[M/2];
            // buscamos la posicion donde se insertara la clave en el padre
            int index = parent->count - 1;
            while (index >= 0 && middle_key < parent->keys[index]){
                parent->keys[index+1] = parent->keys[index];
                index--;
            }
            if (!child->leaf){
                cout << "e UWUWUWUWU" << endl;
                print_Nodo(child->children[0]);
            }
            cout << "i: " << index << endl;
            parent->keys[index+1] = middle_key;
            parent->count++;
            cout << "parent" << endl;
            cout << "size parent: " << parent->count << endl;
            print_Nodo(parent);
            cout << "child[0]" << endl;
            print_Nodo(parent->children[0]);
            cout << "child[1]" << endl;
            print_Nodo(parent->children[1]);
            if (child->children != nullptr){
//                cout << "entro aca" << endl;
//                cout << "child[0] children" << endl;
//                print_Nodo(child->children[0]);
//                cout << "child[1] children" << endl;
//                print_Nodo(child->children[1]);
            }
            // copiar los hijos a su respectivo padre
            auto new_child_left = new Node<T>;
            auto new_child_right = new Node<T>;
            new_child_left->leaf = child->leaf;
            new_child_right->leaf = child->leaf;
            new_child_left->count = M/2;
            new_child_right->count = M - M/2 - 1;
            // copio las claves
            for (int i = 0; i < M/2; ++i) {
                new_child_left->keys[i] = child->keys[i];
            }
            int iter = 0;
            for (int i = M/2+1; i < M; ++i) {
                new_child_right->keys[iter] = child->keys[i];
                iter++;
            }
            cout << "child" << endl;
            print_Nodo(child);
            cout << "ES HOJA: " << child->leaf << endl;
            if (!child->leaf){
                cout << "entro aca" << endl;
                print_Nodo(child->children[0]);
                for (int i = 0; i < M/2+1; ++i) {
                    new_child_left->children[i] = child->children[i];
                }
                iter = 0;
                for (int i = M/2+1; i < M+1; ++i) {
                    new_child_right->children[iter] = child->children[i];
                    iter++;
                }
            }
            cout << "parent ocunt: " << parent->count << endl;
            // desplazar los hijos si es necesario
            for (int i = parent->count - 1; i >= 0; --i) {
                if (parent->children[i] == child){
                    parent->children[i+1] = new_child_right;
                    parent->children[i] = new_child_left;
                    break;
                }
                parent->children[i+1] = parent->children[i];
            }



            cout << "parent" << endl;
            print_Nodo(parent);
            cout << "child[0]" << endl;
            print_Nodo(parent->children[0]);
            cout << "child[1]" << endl;
            print_Nodo(parent->children[1]);
            cout << "child[2]" << endl;
            print_Nodo(parent->children[2]);

            cout << "CHILD" << endl;
            print_Nodo(child);
        }


    }
    void insert_non_full(Node<T>* node,Node<T>* parent, const T& key){
        if (node->leaf){
            insertNonFull(node,key);
        }
        else{
            // buscamos el hijo donde se insertara la clave
            int i = node->count - 1;    // indice de la ultima clave en el nodo
            while ( i >= 0 && key < node->keys[i]){
                i--;
            }
            i++;
            cout << "i: " << i << endl;
            insert_non_full(node->children[i],node,key);
        }
        cout << "vueltas" << endl;
        cout << "print nodo actual" << endl;
        cout << "size: " << node->count << endl;
        for (int i = 0; i < node->count; ++i) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
        cout << "parent" << endl;
        for (int i = 0; i < parent->count; ++i) {
            cout << parent->keys[i] << " ";
        }
        cout << endl;
        if (node->count == M){
            cout << "split" << endl;
            splitchild(node,parent);
        }
    }

    void insertNonFull(Node<T>* node, const T& key) {
        int i = node->count - 1; // Índice de la última clave en el nodo
        // Buscamos la posición para insertar la nueva clave
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i]; // Desplazamos las claves mayores
            i--;
        }

        // Insertamos la nueva clave en su posición adecuada
        node->keys[i+1] = key;
        node->count++;   // aumentamos el numero de claves
    }
    // Método auxiliar para dividir la raíz
    void splitRoot(Node<T>*& root) {
        auto new_child_left = new Node<T>;
        auto new_child_right = new Node<T>;
        new_child_left->leaf = root->leaf;
        new_child_right->leaf = root->leaf;
        new_child_left->count = M/2;
        new_child_right->count = M/2 + 1;
        for (int i = 0; i < M/2; ++i) {
            new_child_left->keys[i] = root->keys[i];
        }
        int iter = 0;
        for (int i = M/2+1; i < M; ++i) {
//            cout << "i: " << i << endl;
//            cout << "root->keys[i]: " << root->keys[i] << endl;
            new_child_right->keys[iter] = root->keys[i];
            iter++;
        }
//        cout << "root->keys[M/2]: " << root->keys[M/2] << endl;
//        cout << "new_child_left->keys[M/2]: " << new_child_left->keys[0] << endl;
//        cout << "new_child_right->keys[0]: " << new_child_right->keys[0] << endl;
        auto new_root = new Node<T>;
        new_root->keys[0] = root->keys[M/2];
        new_root->children[0] = new_child_left;
        new_root->children[1] = new_child_right;
        new_root->count = 1;
        root = new_root;
        root->leaf = false;
    }
    bool is_leaf(Node<T>* node){
        return node->leaf;
    }
    void bfs(Node<T>* node){
        if (node == nullptr){
            return;
        }
        for (int i = 0; i < node->count; ++i) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < node->count+1; ++i) {
            bfs(node->children[i]);
        }

    }
};

int main() {
    Btree<int> btree;

    // Insertamos algunos elementos en el árbol
    btree.insert(10);
    btree.insert(50);
    btree.insert(30);
    btree.insert(60);
    btree.insert(40);
    btree.insert(39);
    btree.insert(45);
    btree.insert(31);
    btree.insert(32);
    btree.insert(33);
    btree.insert(34);
    btree.insert(8);
    btree.insert(7);
    btree.insert(6);
    btree.insert(5);

    //    btree.insert(20);
//    btree.insert(21);
    cout << "bfs tree:" << endl;
    btree.bfs();
    cout << "---------------------------------" << endl;
//    cout << "count root: " << btree.root->count << endl;
//    cout << "keys root: " << btree.root->keys[0] << endl;
//    cout << "---------------------------------" << endl;
//    btree.print_Nodo(btree.root);
//    cout << "---------------------------------" << endl;
//    btree.print_Nodo(btree.root->children[0]);
//    cout << "---------------------------------" << endl;
//
//    btree.print_Nodo(btree.root->children[1]);
//    cout << "---------------------------------" << endl;
//    btree.print_Nodo(btree.root->children[2]);
    // Podemos agregar más inserciones según sea necesario
    return 0;
}
