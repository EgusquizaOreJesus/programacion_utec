#include <iostream>
#include <list>
#include <map>
#include "trie.h"
using namespace std;
const unsigned ALPHA_SIZE = 26;
class TriePatricia : public Trie{
private:
    struct TrieNode{
        string  suffix;
        TrieNode** children;
        bool end_of_word;

        TrieNode():  end_of_word(false)
        { children= new TrieNode * [ALPHA_SIZE];

            for (int i = 0; i < ALPHA_SIZE; ++i) {
                children[i]= nullptr;
            }
        }
        explicit TrieNode(string nueva ): suffix(std::move(nueva)), end_of_word(false)
        { children= new TrieNode * [ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; ++i) {
                children[i]= nullptr;
            }
        }
    };
    TrieNode* root;
public:

    TriePatricia(){
        root = new TrieNode();
    }
    void insert( const string& new_word  ) override{
        int idx= get_index(new_word);
        insert(new_word,0,root->children[idx]);
    }
    void insert(string new_word , int posF , TrieNode* &current){
        if(current== nullptr)
        {
            current= new TrieNode(new_word);
            current->end_of_word= true;
        }else{
            int i=posF;
            int m=int(new_word.size()); // tam de la nueva palabra
            while (i<m or i<current->suffix.size())
            {
                if(new_word[i]!=current->suffix[i])
                    break;
                i++;
            }
            posF=i;
            string new_excess , old_excess , coincidence;
            coincidence=current->suffix.substr(0,posF);
            new_excess=new_word.substr(posF,m);
            old_excess=current->suffix.substr(posF,current->suffix.size());

            current->suffix=coincidence;
            if (!old_excess.empty()) {
                auto* new_node = new TrieNode(old_excess);
                new_node->end_of_word = current->end_of_word;
                current->end_of_word = false;

                for (int j = 0; j < ALPHA_SIZE; ++j) {
                    if (current->children[j] != nullptr) {
                        new_node->children[j] = current->children[j];
                        current->children[j] = nullptr;
                    }
                }

                current->children[get_index(old_excess)] = new_node;

            }
            if(!new_excess.empty())
            {
                insert(new_excess,0,current->children[get_index(new_excess)]);

            }
            if (new_excess.empty() && (old_excess.empty() || !current->end_of_word))
                current->end_of_word = true;
        }

    }
    bool search(string key , TrieNode* current ){

        if(current== nullptr)
            return false;
        else{
            int i=0;
            int m=int(key.size()); // tam de la palabra a buscar
            int n=int(current->suffix.size());
            while (i<m or i<current->suffix.size())
            {
                if(key[i]!=current->suffix[i])
                    break;
                i++;
            }
            string to_find_excess=key.substr(i,m);
            string to_find_old_excess=current->suffix.substr(i,n);

            if(to_find_excess.empty() and to_find_old_excess.empty())
                return current->end_of_word ;
            else if(!to_find_excess.empty() and to_find_old_excess.empty()) return search(to_find_excess , current->children[get_index(to_find_excess)]);

            return false;
        }
    }
    bool search(string key) override{
        return search(std::move(key) , root);
    }
    void remove(string key) override{
        remove(std::move(key) , root);
    }
    void remove(string key , TrieNode* & current){
        if(current== nullptr)
            return ;
        else{
            int i=0;
            int m=int(key.size()); // tam de la palabra a buscar
            while (i<m or i<current->suffix.size())
            {
                if(key[i]!=current->suffix[i])
                    break;
                i++;
            }
            string to_remove_excess=key.substr(i,m);
//            cout<<"ENTRO  "<<to_remove_excess<<"  "<<current->suffix<<endl;
            if(to_remove_excess.empty())
            {

                int cont=0;
                for (int j = 0; j < ALPHA_SIZE; ++j) if(current->children[j] != nullptr)cont++;
                if(cont==0)
                {
                    current->end_of_word= false;
                    current= nullptr;
                }else current->end_of_word= false;
            }
            else remove(to_remove_excess , current->children[get_index(to_remove_excess)]);

            //En el regreso de la recursion se compacta si es necesario

            if(current!= nullptr)
            {
                int cont=0;
                int pos=-1;

                for (int j = 0; j < ALPHA_SIZE; ++j)
                {
                    if(current->children[j] != nullptr)
                    {
                        cont++;
                        pos=j;
                    }
                }
                if(cont==1 and !current->end_of_word)
                {

                    current->suffix+=current->children[pos]->suffix;
                    for (int k = 0; k < ALPHA_SIZE; ++k) {
                        if(current->children[pos]->children[k] != nullptr)
                            current->children[k]=current->children[pos]->children[i];
                    }
                    current->end_of_word= true;
                    current->children[pos]->end_of_word= false;
                    current->children[pos]= nullptr;
                }
            }
        }
    }
    string toString(const string& sep) override{
        return toString(sep,root,"");
    }
    string toString(const string& sep, TrieNode* current, const string& parent) {
        string new_word;
        if (current->end_of_word) {
            new_word += parent + current->suffix+sep;
        }
        for (int i = 0; i < ALPHA_SIZE; ++i) {
            if (current->children[i] != nullptr) {

                new_word +=  toString(sep, current->children[i], parent + current->suffix);
            }
        }
        return new_word;
    }

private:

    static bool is_upper(char c){
        return c>='A' and c <='Z';
    }
    static bool is_lower(char c){
        return c>='a' and c <='z';
    }

    static int get_index(string word)
    {
        if(is_upper(word[0]))
            return word[0]-'A';

        if(is_lower(word[0]))
            return word[0]-'a';


        return -1;
    }
};
