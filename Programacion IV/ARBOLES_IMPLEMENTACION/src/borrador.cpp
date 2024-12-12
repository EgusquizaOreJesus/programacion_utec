#include <iostream>
using namespace std;
// Clase para el nodo del árbol B
class Node {
public:
    int *keys;  // Array para almacenar las claves
    int t;      // Mínimo grado (define el rango de las claves y los hijos)
    Node **children; // Array para almacenar los punteros a los hijos
    int n;     // Número actual de claves almacenadas
    bool leaf; // Verdadero si el nodo es una hoja, falso en caso contrario
    Node(int _t, bool _leaf);   // Constructor

    // Método para insertar una clave en un subárbol enraizado en este nodo
    void insertNonFull(int k);

    // Función auxiliar para dividir el hijo y
    void splitChild(int i, Node *y);

    // Método para recorrer el árbol
    void traverse();

    friend class BTree;
};

// Clase principal para el árbol B
class BTree {
public:

    Node *root; // Puntero al nodo raíz
    int t; // Mínimo grado (define el rango de las claves y los hijos)
    // Constructor (inicializa un árbol vacío)
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    // Método para recorrer el árbol
    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    // Método para insertar una clave en el árbol B
    void insert(int k);
};

Node::Node(int _t, bool _leaf) {
    // Asignar el valor mínimo al grado y si el nodo es una hoja o no
    t = _t;
    leaf = _leaf;

    // Reservar memoria para las claves y los punteros a los hijos
    keys = new int[2*t-1];
    children = new Node *[2 * t];

    // Inicializar el número de claves almacenadas en el nodo como 0
    n = 0;
}

// Método para recorrer el árbol (imprimir las claves en orden ascendente)
void Node::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // Si este no es un nodo hoja, entonces antes de imprimir la clave i, primero recorrer el subárbol enraizado en el hijo i
        if (leaf == false)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }

    // Imprimir el subárbol enraizado en el último hijo
    if (leaf == false)
        children[i]->traverse();
}

// Método para insertar una clave en un subárbol enraizado en este nodo
void Node::insertNonFull(int k) {
    // Inicializar el índice como el índice más a la derecha
    int i = n-1;

    // Si este nodo es una hoja
    if (leaf == true) {
        // Encontrar la ubicación adecuada para insertar la nueva clave y mover todas las claves mayores un espacio hacia adelante
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }

        // Insertar la nueva clave en la ubicación encontrada
        keys[i+1] = k;
        n++;
    }
    else { // Si este nodo no es una hoja
        // Encontrar el hijo que contendrá la nueva clave
        while (i >= 0 && keys[i] > k)
            i--;

        // Comprobar si el hijo encontrado está lleno
        if (children[i+1]->n == 2*t-1) {
            // Si el hijo está lleno, dividirlo
            splitChild(i+1, children[i+1]);

            // Después de dividir, la clave del medio de children[i] se mueve hacia arriba y children[i] se divide en dos. Verificar cuál de los dos hijos nuevos contendrá la nueva clave
            if (keys[i+1] < k)
                i++;
        }
        children[i+1]->insertNonFull(k);
    }
}

// Función auxiliar para dividir el hijo y
void Node::splitChild(int i, Node *y) {
    // Crear un nuevo nodo que almacenará (t-1) claves de y
    Node *z = new Node(y->t, y->leaf);
    z->n = t - 1;

    // Copiar las últimas (t-1) claves de y a z
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    // Copiar los últimos t hijos de y a z
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j+t];
    }

    // Reducir el número de claves en y
    y->n = t - 1;

    // Hacer espacio para el nuevo hijo
    for (int j = n; j >= i+1; j--)
        children[j+1] = children[j];

    // Enlace el nuevo hijo a este nodo
    children[i+1] = z;

    // Mover una clave de este nodo a y
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    // Copiar la clave central de y a este nodo
    keys[i] = y->keys[t-1];

    // Incrementar el número de claves en este nodo
    n++;
}

// Método para insertar una clave en el árbol B
void BTree::insert(int k) {
    // Si el árbol está vacío
    if (root == NULL) {
        // Asignar memoria para la raíz
        root = new Node(t, true);
        root->keys[0] = k;  // Insertar la clave
        root->n = 1;  // Actualizar el número de claves en la raíz
    }
    else { // Si el árbol no está vacío
        // Si la raíz está llena, crecer la altura del árbol
        if (root->n == 2*t-1) {
            // Asignar memoria para la nueva raíz
            Node *s = new Node(t, false);

            // Hacer que la antigua raíz sea el hijo de la nueva raíz
            s->children[0] = root;

            // Dividir la antigua raíz y mover una clave a la nueva raíz
            s->splitChild(0, root);

            // La nueva raíz ahora tiene dos hijos. Decidir cuál de los dos hijos contendrá la nueva clave
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);

            // Actualizar la raíz
            root = s;
        }
        else // Si la raíz no está llena, simplemente insertar la clave en la raíz
            root->insertNonFull(k);
    }
}

// Función principal
int main() {
    BTree tree(3); // Crear un árbol B con mínimo grado 3

    // Insertar claves
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    cout << "n:" << tree.root->n << endl;
    tree.insert(30);
    cout << "n:" << tree.root->n << endl;

    tree.insert(7);
    tree.insert(17);
    cout << "n:" << tree.root->n << endl;
    cout << tree.root->keys[0] << endl;
    // Recorrer el árbol
    std::cout << "Recorrido del árbol B:";
    tree.traverse();
    std::cout << std::endl;

    return 0;
}
