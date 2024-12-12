#include <vector>
//#include "simpletrie.h"
#include "patriciatrie.h"
#include "tester.h"

using namespace std;

void testTrie(Trie* trie, vector<string> diccionario){
    for(string word : diccionario)
        trie->insert(word);
    cout << trie->toString(" ");
    ASSERT(trie->toString(" ") == "amiga amor amorcito amorfo rata roma romano romario rosario ", "The function insert is not working");
    ASSERT(trie->search("amor") == true, "The function search is not working");
    ASSERT(trie->search("rosa") == false, "The function search is not working");
//    trie->remove("roma");
//    trie->remove("amorfo");
//    ASSERT(trie->toString(" ") == "amiga amor amorcito rata romano romario rosario ", "The function remove is not working");
}

//int main(){
////    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};
//
////    testTrie(new TrieSimple(), diccionario);
////    testTrie(new TriePatricia(), diccionario);
//
//    return 0;
//}
#include <iostream>
#include <string>

int main() {
    std::string str = "123";
    double numero_double = std::stod(str);
    std::cout << numero_double << std::endl;
    return 0;
}