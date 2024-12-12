#include <iostream>
#include <list>
#include <map>
#include "trie.h"
using namespace std;


class TriePatricia : public Trie{
private:
    struct TrieNode{
        // opcion 1:   TrieNode **children;
        // opcion 2:   list<pair<char, TrieNode*>> children;
        // opcion 3:   map<pair<char, TrieNode*>> children;
        map<char, TrieNode*> children;
        string preffix;
        bool endWord; //indica si es final de una palabra

        TrieNode() {
            endWord = false;
        }
        TrieNode(string palabra_) {
            preffix = std::move(palabra_);
            endWord = false;
        }
        ~TrieNode();

    };
    TrieNode* root;

public:
    TriePatricia(){
        root = new TrieNode();

    }
    void insert(string palabra) {
        TrieNode* current = root;

        for (const char& c : palabra) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode(palabra);
            }
            current = current->children[c];
        }

        current->endWord = true;
    }

    bool search(string palabra) {
        TrieNode* current = root;

        for (const char& c : palabra) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }

        return current->endWord;
    }

    void remove(string key){
        return;
    };

    //imprime ordenado
    string toString(string sep,TrieNode* node) {
        string result;
        if (node == nullptr) {
            return result;
        }

        if (node->endWord) {
            result += node->preffix + sep;
        }

        for (const auto& pair: node->children) {
            result += toString(sep,pair.second);
        }

        return result;
    }
    string toString(string sep){
        return toString(sep,root);
    }
};