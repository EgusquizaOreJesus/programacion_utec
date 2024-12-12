//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <utility
#include "vector"

//
//using namespace std;
//
//class Node {
//public:
//    unordered_map<char, Node*> children;
//    bool isEndOfWord;
//    string palabra;
//
//    Node() {
//        isEndOfWord = false;
//    }
//    Node(string palabra_) {
//        palabra = std::move(palabra_);
//        isEndOfWord = false;
//    }
//};
//
//class Trie {
//private:
//    Node* root;
//
//public:
//    Trie() {
//        root = new Node();
//    }
//
//    void insert(const string& word) {
//        Node* currentNode = root;
//
//        for (int i = 0; i < word.length(); ++i) {
//            char prefix = word[i];
//
//            if (currentNode->children.find(prefix) == currentNode->children.end()) {
//                Node* newNode = new Node(word);
//                currentNode->children[prefix] = newNode;
//                currentNode = newNode;
//            } else {
//                currentNode = currentNode->children[prefix];
//            }
//        }
//
//        currentNode->isEndOfWord = true;
//    }
//
//    bool search(const string& word) {
//        Node* currentNode = root;
//
//        if (word.empty()) {
//            return false;
//        }
//
//        char prefix = word[0];
//
//        if (currentNode->children.find(prefix) == currentNode->children.end()) {
//            return false;
//        } else {
//            currentNode = currentNode->children[prefix];
//        }
//
//        return currentNode != nullptr && currentNode->isEndOfWord;
//    }
//};
//
//int main() {
//    Trie radixTree;
//
//    radixTree.insert("apple");
//    radixTree.insert("banana");
//    radixTree.insert("orange");
//
//    cout << "Search 'a': " << (radixTree.search("apple") ? "Found" : "Not found") << endl;
//    cout << "Search 'b': " << (radixTree.search("b") ? "Found" : "Not found") << endl;
//    cout << "Search 'o': " << (radixTree.search("o") ? "Found" : "Not found") << endl;
//    cout << "Search 'g': " << (radixTree.search("g") ? "Found" : "Not found") << endl;
//
//    return 0;
//}
#include <iostream>
#include <unordered_map>
#include "map"
using namespace std;
class Node {
public:
    map<char, Node*> children;
    bool isEndOfWord;
    string palabra;

    Node() {
        isEndOfWord = false;
    }
    Node(string palabra_) {
        palabra = std::move(palabra_);
        isEndOfWord = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& palabra) {
        Node* current = root;
        for (const char& c : palabra) {
            if (current->children[c] == nullptr) {
                current->children[c] = new Node(palabra);
            }
            else{
                current = current->children[c];
                cout << current->palabra;
                if (palabra.length() > current->palabra.length()){

                }
            }
        }

        current->isEndOfWord = true;
    }
    void insert2(const string& palabra) {
        Node* current = root;
        for (const char& c : palabra) {
            if (current->children.find(c) == current->children.end()) {
                cout << "NO SE ENCUENTRA" << endl;
                current->children[c] = new Node();  // Crea un nuevo nodo solo si no existe
            }
            cout << "palabra current: "<<current->palabra << endl;
            cout << "c:" << c <<endl;
            current = current->children[c];
        }
        cout << "palabra current: "<<current->palabra << endl;

        current->isEndOfWord = true;
        current->palabra = palabra;  // Actualiza la palabra solo en el último nodo
    }

        bool search(const string& palabra) {
            Node* current = root;

            for (const char& c : palabra) {
                if (current->children.find(c) == current->children.end()) {
                    return false;
                }
                current = current->children[c];
            }

            return current->isEndOfWord;
        }
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        for (const auto& pair : node->children) {
            inorder(pair.second);
        }

        if (node->isEndOfWord) {
            cout << node->palabra << endl;
        }
    }
    string to_string(Node* node) {
        string result;
        if (node == nullptr) {
            return result;
        }

        if (node->isEndOfWord) {
            result += node->palabra + " ";
        }

        for (const auto& pair : node->children) {
            result += to_string(pair.second);
        }

        return result;
    }
    string to_string(){
        return to_string(root);
    }
};

int main() {
//    Trie tree;
//    tree.insert2("romano");
////    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};
////    for(string word : diccionario)
////        tree.insert2(word);
//
//    cout << tree.to_string();
    string x = "Romano";

    return 0;
}
