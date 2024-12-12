#include <iostream>
#include "vector"
using namespace std;
/**
        GRAFOS
 UN CONJUNTO DE VERTICES Y ARISTAS
 - El grado del vertice: es la cantidad de aristas que se conectan
 - Vertices hundidos - sumideros: son los que solamente tienen entradas de arista
 - Vertices fuente: Que solamente tiene salidas de aristas
CAMINO: TODOS LOS NODOS DEBEN SER ADYACENTES
grafo ciclico: grafo que contiene al menos un ciclo se llama ciclico
 aciclico: sera aquel que no tiene ningun ciclo

 UN ARBOL ES UN GRAFO ACICLICO, SI O SI SOLAMENTE DEBE TENER UN VERTICE FUENTE
 Un arbol es un tipo especial de grafo donde se tiene un nodo raiz y una relacion de paternidad entre nodos
 Los nodos hijos (excluyendo la raiz) son particionados en sub-arboles
 Los nodos que no tienen hijos se les denomina hojas
 Solo existe un camino entre dos nodos

 Un grafo arbol puede ser transformado en un arbol al elegir un nodo como su raiz y definiendo
 sus vertices vecinos con sus hijos

 arbol de expansion:

 GRAFO SIMPLE: no tiene loops ni multiples aristas
 loop: es una arista asi misma
 GRAFO COMPLETO: Cada par de vertices esta conectado por una arista
 ---> OSEA CADA VERTCE SE CONECTA CON TODOS
 -- SOBRE UN GRAFO COMPLETO YA NO PUEDO PONER MAS ARISTAS, ES LO MAXIMO A LO QUE PUEDO LLEGAR
 Multigrafo: Las aristas pueden tener mas de una conexion

 GRADO DE UN VERTICE: ENTRADA + SALIDA

 EL VERTICE A ES ADYACENTE AL VERTICE C:
 NO, YA QUE NO COMPARTEN UNA ARISTA




 - G = (V,E); V:VERTICES , E: aristas
NO DIRIGIDO:
 max E => v*(v-1)/2
DIRIGIDO
 V = (a,b,c,d)
 Para un grafo dirigido:

 a => (a,b) (a,c) (a,d) 3
 b => (b,a) (b,c) (b,d) 3
 c =>                   3
 d =>                   3
                    --------
                        12
 max E = v*(v-1)
DENSIDAD:
 PARA SABER SI UN GRAFO ES DENSO O NO
 TENGO QUE USAR LA SIGUIENTE FORMULA
 GRAFO NO DIRIGIDO:  D = 2E/V(V-1)
 GRAFO DIRIGIDO:     D = E/V(V-1)
 Y SI ES MAYOR O IGUAL A NUESTRO FACTOR DE DENSIDAD QUE TU LO DEFINES ENTONCES ES DENSO

 GRAFOS PONDERADOS:

 CUAL ES EL CAMINO MINIMO EN FUNCION A LOS PESOS:


*/
/**
    IMPLEMENTACION DE GRAFO
- Una forma de implementarlo ens
 - Usando arrays/ listas enlazadas
 struct Edge{       // estrucutra de aristas(edge)
    string startVertex;
    string endVertex;
    float weight;

};

class Graph{
    vector<string> vertex;
    vector<Edge*> edges;
};

 Espacio: O(V) + 0(E)

 Porque esta estructura no es eficiente?
 - Cuanto toma encontrar los nodos adyacentess a un nodo?
 ---> necesito recorrer el vector de aristas vector<Edge*>
 --->   O(V*(V-1)) -> ya que en el peor de los casos tengo que recorrer todas las aristas
 ---> O(v^2)
 OBS: En grafos siempre hay que poner la complejidad en funcion de V
 - Saber si dos vertices estan conectados?
 --> recorrer vector<Edge*> --> 0(V^2)

 --> ENTONCES ESTA ESTRUCTURA NO ES EFICIENTE

--> ENTONCES IMPLEMENTAREMOS DOS FORMAS DE IMPLEMENTAR EL GRAFO (DE MANERA MAS EFICIENTE)

 */
 /**
                MATRIZ DE ADYACENCIA:
  La matriz de adyacencia requiere una matriz de tamaño V^2
  -- Complejidad espacial: O(V^2)

  Es 1 cuando hay conexion entre aristas
  Es 0 cuando no hay conexion entre aristas

  Con esta implementacion:
  Cuanto me costara encontrar todo los vertices adyacentes a un vertice
  --> O(V) ya que vas hacia la posicion de la arista que quieres y recorres esa arista

  -- Cuanto me cuesta saber si dos vertices estan conectados:
  --> O(1) aqui TENEMOS TREMENDA VENTAJA

  DESVENTAJAS:
  1. El espacio, requiere una matriz cuadrada
  Que pasa si una matriz representa un grafo disperso, osea pocas conexiones
  Un grafo disperso tendria una matriz dispersa, con muchos ceros, MUCHO ESPACIO QUE NO UTILIZAS
  ---> UN GRAFO DISPERSO ES DEMASIADO COMUN EN LA VIDA REAL
  MUCHO DESPERDICIO DE MEMORIA
  GRAFO NO DIRIGIDO, HAY MAS DESPERDICIO DE MEMORIA POR SER REDUNDANTE:
  ----> ARRAY DINAMICO SOLUCION PARA UN GRAFO NO DIRIGID0, PODRIAMOS RECORRER CADA DATA V,V-1,V-2,.....1

  - OTRA DESVENTAJA:
  ES A LA HORA DE ELIMINAR E INSERTAR ES DEMASIADO COSTOSO:
  ---> ES REDIMENSIONAR LA MATRIZ
  */

/**
               LISTA DE ADYACENCIA:
    UNA SOLUCION A UN ARRAY DISPERSO, ES LA LISTA DE ADYACENCIA
    PARA ENLAZAR AQUELLAS CELDAS QUE CONTENGAN LA INFORMACION
    Y PARA QUE PERMITA INSERCIONES MENOR AL O(N^2) ES ESTE

    NECESITAMOS UN ARRAY DE VERTICES, Y CADA VERTICE VA TENER TODAS SUS CONEXIONES EN UNA LISTA

    Cuanto espacio requiere?
    --> El tamaño de la lista

    --- OBS:
    En un grafo denso, para un grafo completo la mejor forma es mejor usar la matriz de adyacencia
    En un grafo disperso, conviene mejor la lista

    Para la insercion:
    Para un grafo no dirigido:
    su complejidad es O(2v)
    Para un grafo dirigido:
    su complejidad es O(V)

    para eliminar:
    Para un grafo dirigo
    Su complejodad es O(V)
    Una implementeacion seria:
    struct Edge{
        Vertex* startVertex;
        Vertex* endVertex;
        TE weight;

    }

    class graph{
        vector<list<Edge>> ady;
     }

     Para una lista de adyacencia:

     Para saber si dos vertices estan conectados:
     ---> O(V)

 */

/**
                DISJOINT SETS (UNION-FIND)
 Conjuntos disjuntos: Que no tienen elementos en comun (interseccion vacia)
 Ejm:
 A = {a,b,c,d}
 B = {x,y,z}
 C = {h,i,j}

 Debe soportar las funciones
 find(c) = A

 une el conjunto que pertenece x con el conjunto que pertenece d
 union(x,d) = find(x) U find(d)
            = {x,y,z,a,b,c,d}
--------------------------------
 usando arrays:
 find(c)        --> O(n), peor caso es buscar en todo los conjuntos
 union(x,d)     --> O(n)        +       O(n)        +      O(n)
                  buscar x             buscar d           copiar en un array
  usando listas:
  find(c)       --> O(n)
  union(x,d)    --> O(n) + (n) + O(1): porque de una lista conecto la cola con la cabeza de la otra

  usando avl:
  ¿Cual seria mejor un arbol con todo los conjuntos, o cada conjunto es un arbol?

  si fuera para cada conjunto un arbol:
  find(c)       --> O(log n)*k; siendo k la cantidad de arboles por cada conjunto

  se puede meter todo los conjuntos en un arbol:
  lo puedo meter en un arbol binario, el value seria el conjunto y la llave seria los valores de dicho conjunto
  find(c)       --> O(log n)
  union(x,d)    --> voy a buscar todos ellos y voy a cambiar su values a 1 solo
   primero:
   find(x) + find(d) + luego recorre en inorder inorder() B,C --> X

 * usando hash con todos los elementos:
    hashtable = {(a:A), (b:A), (c,A), ... , (x:B), (y:B), ..., (h:C)}
    union(x,d) => O(1) + O(1) + O(n)

 OPTIMIZACION 1:
 ---------------
 find(c)    --> O(k) , tiende a ser O(1) k < log(n), siendo k el rank (altura)



 OPTIMIZACION 2:
 path compression

 IMPLEMENTACION
 LA MEJOR MANERA ES CON ARRAYS:

 T data[]
 necesito dos arrays, para los padres y rangos
 int parent[]
 int rank[]

 funciones:
 Makeset(int x)
 Find(int x)
 Union(int x, int y)


                KRUSKAL
 Como trabaja el kruskal:
 Trabaja solo con aristas, entonces sirve para grafos no conexos
 en grafos conexos seria un bosque
 Que hace:
1. Ordena las aristas en funcion de su peso
2. Aplicar Maekset a todos los vertices
3. Recorrer todas las aristas y agregar al arbol MST
    3.1. Agregar aristas e = (v1,v2) a la solucion si cumple:
    Find(v1) != Find(v2)

    3.2. Luego Unir v1 y v2
        Union(v1,v2)
 */

/**
                 PRIM
El prim recibe como parametro un vertice, y a partir de ahi se comienza a expandir

 */
struct Edge{
    string startVertex;
    string endVertex;
    float weight;

};

class Graph{
    vector<string> vertex;
    vector<Edge*> edges;
};
int main() {
    string a = "abcd";
    string b = "abd";
    cout << boolalpha << (a>b);
    return 0;
}
