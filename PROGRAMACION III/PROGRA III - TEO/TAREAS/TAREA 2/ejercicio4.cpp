#include <iostream>

using namespace std;
class point {
    int x;
    int y;
public:
    point(int x, int y): x{x}, y{y} {}
    point() = default;

    friend ostream& operator<< (ostream& os, const point& p) {
        os << "{" << p.x <<", " << p.y << "}" << endl;
        return os;
    }

    [[nodiscard]] int get_x() const { return x; }
    [[nodiscard]] int get_y() const { return y; }
};

// A generic smart pointer class
template <typename T=int>
class smart_ptr {
    T* ptr = nullptr; // Actual pointer
public:
    // Constructor
    smart_ptr() {
        ptr = new T();
    };
    smart_ptr(const smart_ptr& other){
        ptr = new T(*other.ptr);
    }
    smart_ptr& operator=(const smart_ptr& other){    // OPERADOR DE ASIGNACION COPIA
        if (this!=&other){
            delete ptr;
            ptr = new T(*other.ptr);
        }
        return *this;
    }

    // Destructor
    ~smart_ptr() { delete (ptr); }

        // Overloading dereferencing operator

    T& operator*() { return *ptr;} // se comporta como un get
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};

template<>
class smart_ptr<point> {
    point* ptr = nullptr; // Actual pointer
public:
    // Constructor
    smart_ptr() = default;
    smart_ptr(int a, int b){
        auto* y = new point(a,b);
        ptr = y;
    }
    smart_ptr(const smart_ptr& other){
        ptr = new point(*other.ptr);
    }
    smart_ptr& operator=(const smart_ptr& other){    // OPERADOR DE ASIGNACION COPIA
        if (this!=&other){
            delete ptr;
            ptr = new point(*other.ptr);
        }
        return *this;
    }

    // Destructor
    ~smart_ptr() { delete (ptr); }

    // Overloading dereferencing operator

    point& operator*() { return *ptr;} // se comporta como un get
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    point* operator->() { return ptr; }
};




template <typename Ts=int>
smart_ptr<Ts> make_smart_ptr(const Ts& a){
    smart_ptr<Ts> b;
    *b = a;
    return b;
}

template <typename T=int>
smart_ptr<point> make_smart_ptr(int a, int b){
    smart_ptr<point> x(a,b);
    return x;
}
// FALTA UN CASO
int main()
{
    smart_ptr<point> sp1; // puntero inteligente no inicializado
    sp1 = make_smart_ptr<point>(20, 30);

    cout << *sp1 << endl;   // Imprimiendo el contenido

    smart_ptr<point> sp2 = make_smart_ptr<point>(10, 40); // puntero inteligente no inicializado

    cout << sp2->get_x() << endl;
    cout << sp2->get_y() << endl;
    return 0;
}
