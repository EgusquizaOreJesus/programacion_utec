#include "iostream"
#include "algorithm"
#include "cmath"
#include "vector"

using namespace std;
class Cipher{
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a;
    int b;
public:
    Cipher(int x, int y):a(x),b(y){};
    string operator() (const string& s){
        string temp;
        for (auto e: s) {
            auto pos = find(ABC.begin(),ABC.end(),e);
            int pos1 = distance(ABC.begin(),pos);
            int c = ((a*pos1) + b)%26;
            temp += ABC[c];
        }
        return temp;
    }

};
int main () {
    Cipher F (5 ,6) ; // Functor para cifrar , a =5 y b =6
    cout << F( "Y") << endl ; // Resultado : W
    Cipher H (21 ,4) ; // Functor para descifrar , a =21 y b =4
    cout << H( F ( "Y") ) << endl ; // Resultado : Y
    string s = " PROGRAMACION " ;
    cout << " Cifrando ... PROGRAMACION " << endl ;
    Cipher S(5,6);
    cout << S(s) << endl;
    string u = " PYJGOCTVYATQOGSOGS " ;
    cout << " Descifrando ... PYJGOCTVYATQOGSOGS " << endl ;
    Cipher U(21,4);
    cout << U(u) << endl;

}