#include <utility>

#include "map"
#include "iostream"
#include "unordered_map"

using namespace std;

struct TrieNode {
public:
    string palabra;
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode(string c) {
        palabra = std::move(c);
        isEnd = false;
    }
    TrieNode(){
        isEnd = false;
    };
};
class Trie {
private:
    TrieNode* root;
    void insert(string word, TrieNode* raiz){
        TrieNode* current = raiz;

        if (current->children.find(word[0]) == current->children.end()) {
            current->children[word[0]] = new TrieNode(word);
        }
        else{
            current = current->children[word[0]];
            if (word.length() > current->palabra.length()){
                string temp;
                string temp2;
                int j = 0;
                int pos = 0;
                for(char c: current->palabra){
                    if (c == word[j++]){
                        pos++;
                    }
                }

                cout << "palabra igual:" << temp2 << endl;

                cout << "palabra diferente:" << word.substr(pos) << endl;
                insert(word.substr(pos),current);
            }
        }
        current->isEnd = true;
    }
//    void insert(string word, TrieNode* raiz){
//        TrieNode* current = raiz;
//
//        if (current->children.find(word[0]) == current->children.end()) {
//            current->children[word[0]] = new TrieNode(word);
//        }
//        else{
//            current = current->children[word[0]];
//            string temp = current->palabra;
//            int j = 0;
//            while (j < word.length() && j < temp.length() && word[j] == temp[j]) {
//                j++;
//            }
//
//            if (j == temp.length()) {
//                insert(word.substr(j), current);
//            }
//            else {
//                TrieNode* newChild = new TrieNode(temp.substr(j));
//                current->palabra = temp.substr(0, j);
//                current->children[temp[j]] = newChild;
//                current = new TrieNode(word.substr(j));
//                newChild->children[word[j]] = current;
//                current->isEnd = true;
//            }
//        }
//        current->isEnd = true;
//    }

    void inorderTraversal(TrieNode* node, string& result) {
        if (node == nullptr) {
            return;
        }

        for (const auto& child : node->children) {
            inorderTraversal(child.second, result);
            result += child.second->palabra + " ";

        }
    }
public:
    Trie() {
        root = new TrieNode();
    }

    void insert2(string word){
        insert(std::move(word),root);
    }

    string to_string() {
        string result;
        inorderTraversal(root, result);
        return result;
    }
    bool search(const string& palabra) {
        TrieNode* current = root;

        for (const char& c : palabra) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }

        return current->isEnd;
    }

};
int main(){
    Trie trie;
    trie.insert2("roma");
//    trie.insert2("romano");
    string trieString = trie.to_string();
    cout << "Trie palabras: " << trieString << endl;

    cout << trie.search("roma");
    trie.search("romano");
    trie.search("italia");

    return 0;
}
