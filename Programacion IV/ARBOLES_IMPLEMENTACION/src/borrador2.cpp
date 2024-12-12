#include <iostream>
#include <string>

using namespace std;

class RadixTreeNode {
public:
    string key;
    RadixTreeNode* children[26];
    bool isWord;

    RadixTreeNode() {
        key = "";
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Trie {
private:
    RadixTreeNode* root;

public:
    Trie() {
        root = new RadixTreeNode();
    }

    void insert(const string& word) {
        insertRecursive(root, word);
    }

    void inorder() {
        inorderRecursive(root);
    }
    bool search(const string& word) {
        return searchRecursive(root, word);
    }
private:
    void insertRecursive(RadixTreeNode* node, const string& word) {
        if (word.empty()) {
            node->isWord = true;
            cout << "acabo" << endl;
            return;
        }
        cout << "palabra: " <<word << endl;
        char firstChar = word[0];
        int index = firstChar - 'a';
        cout << "index: " << index << endl;
        if (node->children[index] == nullptr) {
            cout << "children vacio" << endl;
            node->children[index] = new RadixTreeNode();
            node->children[index]->key = node->key + firstChar;
        }
        else{
            cout << "index encontrado" << endl;
        }

        string remaining = word.substr(1);
        insertRecursive(node->children[index], remaining);
    }

    void inorderRecursive(RadixTreeNode* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            inorderRecursive(node->children[i]);
        }

        if (node->isWord) {
            cout << node->key << endl;
        }
    }


    bool searchRecursive(RadixTreeNode* node, const string& word) {
        if (word.empty()) {
            return node->isWord;
        }

        char firstChar = word[0];
        int index = firstChar - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }

        string remaining = word.substr(1);
        return searchRecursive(node->children[index], remaining);
    }

};

int main() {
    Trie tree;
    tree.insert("apple");
    tree.insert("pple");

//    tree.insert("banana");
//    tree.insert("application");
//    tree.insert("apply");

    cout << "Inorder traversal:" << endl;
    tree.inorder();
    cout << boolalpha <<tree.search("application");

    return 0;
}
