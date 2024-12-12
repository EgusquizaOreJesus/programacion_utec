#include <string>

using namespace std;

class Trie
{
public:
    virtual void insert(const string& ) = 0;
    virtual bool search(string key) = 0;
    virtual void remove(string key) = 0;        
    
    //imprime ordenado
    virtual string toString(const string& sep=",") = 0;
};
