#include <vector>
#include "patriciatrie.h"
#include "simpletrie.h"
#include "tester.h"

using namespace std;

void testTrie(Trie* trie, const vector<string>& diccionario){
    for(const string& word : diccionario)
        trie->insert(word);

    ASSERT(trie->toString(" ") == "amiga amor amorcito amorfo rata roma romano romario rosario ", "The function insert is not working");
    ASSERT(trie->search("amor") == true, "The function search is not working");
    ASSERT(trie->search("rosa") == false, "The function search is not working");
    trie->remove("roma");
    trie->remove("amorfo");
    ASSERT(trie->toString(" ") == "amiga amor amorcito rata romano romario rosario ", "The function remove is not working");
}

int main(){
    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};
    
    testTrie(new TrieSimple(), diccionario);
   testTrie(new TriePatricia(), diccionario);
    
    return 0;
}
