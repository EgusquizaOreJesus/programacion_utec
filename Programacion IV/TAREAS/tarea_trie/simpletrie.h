#include <iostream>
#include "trie.h"

using namespace std;

const unsigned ALPHA_SIZE = 26;//tamanio del alfabeto: letras minusculas

class TrieSimple : public Trie {
private:
    struct TrieNode{
        // opcion 1:   TrieNode **children;           
        // opcion 2:   list<pair<char, TrieNode*>> children;        
        // opcion 3:   map<pair<char, TrieNode*>> children;   
        TrieNode **children;        
        bool endWord; //indica si es final de una palabra
        
        TrieNode();        
        ~TrieNode();
    };

    TrieNode* root;

public:
    TrieSimple(): root(nullptr) {}

    void insert(string key);

    bool search(string key);

    void remove(string key);    
    
    //imprime ordenado
    string toString(string sep);

};
