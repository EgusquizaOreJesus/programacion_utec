#include <functional>
#include "stack"
#include "iostream"
#include "vector"

using namespace std;
class alumno_t{
    string apellido;
    string nombre;
    int nota;
public:
    alumno_t(const string& a, const string& n, int nota_):apellido(a),nombre(n),nota(nota_){};
    string get_nombre(){
        return nombre;
    }
    string get_apellido(){
        return apellido;
    }
    [[nodiscard]] int get_nota() const{
        return nota;
    }

};

template<typename T=alumno_t>
T find_in_stack(stack<T> s, function<bool(T)> cmpr)
{
    while (!s.empty())
    {
        if(cmpr(s.top()))
            return s.top();

        s.pop();
    }
}

int main(){
    stack<alumno_t> s1;
    int n{};
    cin >> n;
    string nombre;
    string apellido;
    double nota;
    while (n-- > 0) {
        getline(cin, nombre);
        getline(cin, apellido);
        cout << nombre;
        cout << apellido;
        cout << endl;
//        cin.ignore();
//        cin >> nota;
//        s1.push(alumno_t{nombre, apellido, static_cast<int>(nota)});
        cout << n << endl;
    }
//
//    string name_tobe_found;
//    getline(cin, name_tobe_found);
//    auto a1 = find_in_stack<alumno_t> (s1, [=](auto a) { return a.get_nombre() == name_tobe_found; });
//    cout << a1.get_nombre() << " " << a1.get_apellido() << " " << a1.get_nota() << endl;


    return 0;
}