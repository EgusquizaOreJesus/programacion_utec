#include "iostream"

/**
        ARBOL B+
 -- LOS NODOS INTERNOS SE MANEJAN COMO UN ARBOL B
 struct InternalNode: public Node
 {
    TK keys[M-1];
    Node* children[M];
    int count;
 }
 LOS NODOS HOJAS VAN ENLAZADAS
 struct LeafNode: public Node
 {
   TK keys[M-1];
   TV values[M-1];
   LeafNode* next;
   int count;
 }
 - LOS NODOS INTERNOS YO LOS CARGO EN LA RAM
 OBS: LA CPU NO TRABAJA CON LA MEMORIA SECUNDARIA
 - LOS NODOS HOJAS VAN A LA MEMORIA SECUNDARIA
 EN LAS HOJAS DEBE ESTAR TODA LA INFORMACION NO SE DEBE PERDER NADA EN LAS HOJAS
 BORRADO:

 PORQUE SE USA B+?
 -
 */



int main(){



    return 0;
}