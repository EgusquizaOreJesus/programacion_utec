#include <iostream>
#include <fstream>
#include "vector"
#include "set"
#include "list"
using namespace std;

template<typename T=string, template<typename ...>typename Container = vector>
Container<T> filter_codes(const string& nombre, const char& c){
    ifstream file(nombre.c_str());
    string line;
    Container<T> result;
    vector<string> codes;
    while(getline(file,line)) {
        codes.push_back(line);
    }
    std::sort(codes.begin(), codes.end());
    copy_if(codes.begin(),codes.end(), back_inserter(result),[c](string x){
        return x[0] == c;
    });
    return result;
}


int main() {
    vector<string> codes = filter_codes("archivo.txt", 'c');
    vector<string> palabras = {"hola","adios","bebecita"};
    set<string> yes(palabras.begin(),palabras.end());
    for_each(yes.begin(),yes.end(),[](const string& x){cout << x << " ";});
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
    return 0;
}