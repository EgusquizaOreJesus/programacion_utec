#include <iostream>

using namespace std;

//tamanio del alfabeto: letras minusculas
class TrieSimple: public Trie{
private:
    struct TrieNode{
        // opcion 1:   TrieNode **children;
        // opcion 2:   list<pair<char, TrieNode*>> children;
        // opcion 3:   map<pair<char, TrieNode*>> children;
        TrieNode **children;
        bool endWord; //indica si es final de una palabra

        TrieNode(){

            children = new TrieNode*[ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; ++i) {
                children[i]= nullptr;
            }
            endWord= false;
        }

        ~TrieNode()= default;
    };

    TrieNode* root;

public:
    TrieSimple(): root(new TrieNode()) {}

    void insert(const string&  key) override{
        insert(key,root,0);
    }

    void insert(string key , TrieNode* &current , int c_pos){


//            cout<<"Haciendo el esfuerzo "<<key[c_pos]<<" "<<c_pos<<" "<<key.size()<<endl;
        if(current== nullptr)
            current=new TrieNode();

        if(c_pos==key.size())
        {

            current->endWord= true;
            return;

        }else{


            insert(key,current->children[get_index(key[c_pos])],c_pos+1);

        }
    }
    bool search(string key ) override{

        TrieNode* temp = root;
        [[maybe_unused]]int idx=-1;
        for(auto c:key)
        {
            idx = get_index(c);
            if(temp!= nullptr)
                temp=temp->children[idx];
            else return false;
        }
        return temp->endWord;

    }
    void remove(string key , TrieNode* & current, int c_pos , bool &erase){


        if(current== nullptr)
        {
            erase= false;
            return;

        }

        if(c_pos==key.size())
        {
            erase=current->endWord;
            current->endWord= false;
        }else remove(key,current->children[get_index(key[c_pos])],c_pos+1,erase);


//        recursion turn back
        int cont=0;
        for (int i = 0; i < ALPHA_SIZE; ++i)if(current->children[i]!= nullptr)cont++;
        erase= (cont <= 0);

        if(erase)
            current= nullptr;
    }
    void remove(string key) override{
        bool erase = false;
        remove(key , root,0, erase);

    }


    string toString(const string& sep) override {

        return toString(sep, root, "", 0);
    }

    string toString(const string& sep, TrieNode* current, const string& prefix, [[maybe_unused]]int pos ) {
        string word;
        if (current->endWord) {
            word += prefix + sep;
        }
        for (int i = 0; i < ALPHA_SIZE; ++i) {
            if (current->children[i] != nullptr) {


                char currentChar = static_cast<char>(i + 'a');
                string newPrefix = prefix;
                newPrefix.push_back(currentChar);

                word += toString(sep, current->children[i], newPrefix,i);
            }
        }


        return word;
    }

private:
    [[maybe_unused]]static bool is_upper(char c){
        return c>='A' and c <='Z';
    }
    static bool is_lower(char c){
        return c>='a' and c <='z';
    }
    static int get_index(char word)
    {
        if(is_lower(word))
            return word-'a';
        return -1;
    }
};
