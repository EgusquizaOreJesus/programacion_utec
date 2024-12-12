#include "iostream"

using namespace std;

class BTree {
public:
    BTree(int degree) {
        root = nullptr;
        M = degree;
    }

    void insert(int key) {
        if (root == nullptr) {
            // Si el árbol está vacío, creamos un nuevo nodo y lo establecemos como raíz
            root = new Node(M, true);
            root->keys[0] = key;
            root->count = 1;
        } else {
            if (root->count == (2 * M - 1)) {
                // Si la raíz está llena, creamos un nuevo nodo y lo establecemos como nueva raíz
                Node* newNode = new Node(M, false);
                newNode->children[0] = root;
                root = newNode;

                // Dividir el hijo anterior de la raíz (que ahora es el primer hijo)
                splitChild(0, root);

                // Insertar la clave en el subárbol adecuado
                insertNonFull(root, key);
            } else {
                // Si la raíz no está llena, simplemente insertamos la clave
                insertNonFull(root, key);
            }
        }
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }
//
//private:
    struct Node {
        int* keys;
        int M;
        Node** children;
        int count;
        bool leaf;

        Node(int degree, bool isLeaf) {
            M = degree;
            leaf = isLeaf;
            keys = new int[2 * M - 1];
            children = new Node*[2 * M];
            count = 0;
        }
        void traverse(){
            int i;
            for (i = 0; i < this->count; i++) {
                // Si este no es un nodo hoja, entonces antes de imprimir la clave i, primero recorrer el subárbol enraizado en el hijo i
                if (!leaf)
                    children[i]->traverse();
                std::cout << " " << keys[i];
            }

            // Imprimir el subárbol enraizado en el último hijo
            if (!leaf)
                children[i]->traverse();
        }
    };

    Node* root;
    int M;

    void splitChild(int i, Node* parent) {
        Node* child = parent->children[i];
        Node* newChild = new Node(M, child->leaf);
        newChild->count = M - 1;

        for (int j = 0; j < M - 1; j++) {
            newChild->keys[j] = child->keys[j + M];
        }

        if (!child->leaf) {
            for (int j = 0; j < M; j++) {
                newChild->children[j] = child->children[j + M];
            }
        }

        child->count = M - 1;

        // Desplazar los hijos del nodo padre para hacer espacio para el nuevo hijo
        for (int j = parent->count; j > i; j--) {
            parent->children[j + 1] = parent->children[j];
        }

        // Establecer el nuevo hijo en la posición correcta
        parent->children[i + 1] = newChild;

        // Desplazar las claves del nodo padre para hacer espacio para la nueva clave
        for (int j = parent->count - 1; j >= i; j--) {
            parent->keys[j + 1] = parent->keys[j];
        }

        // Establecer la nueva clave en la posición correcta
        parent->keys[i] = child->keys[M - 1];

        parent->count++;
    }

    void insertNonFull(Node* node, int key) {
        int i = node->count - 1;

        if (node->leaf) {
            // Si el nodo es una hoja, insertar la clave en la posición correcta
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }

            node->keys[i + 1] = key;
            node->count++;
        } else {
            // Si el nodo no es una hoja, encontrar el hijo adecuado y asegurarse de que no esté lleno
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }

            i++;

            if (node->children[i]->count == (2 * M - 1)) {
                splitChild(i, node);

                if (key > node->keys[i]) {
                    i++;
                }
            }

            insertNonFull(node->children[i], key);
        }
    }
};


// Función principal
int main() {
    BTree tree(3); // Crear un árbol B con mínimo grado 3
    // Insertar claves
    tree.insert(10);

    tree.insert(20);
    tree.insert(5);

    tree.insert(6);

    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    cout << "count root: " << tree.root->count << endl;

//    // Recorrer el árbol
//    std::cout << "Recorrido del árbol B:";
    tree.traverse();
//    std::cout << std::endl;

    return 0;
}
