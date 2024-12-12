#include "iostream"
#include "string"

using namespace std;


/// ESTO ES TODO LO QUE HACE SINGLETON
class Singleton {
private:
    Singleton(): greeting_(new string) {}               // Deshabilita constructor
    /// ATRIBUTOS DE TIPO ESTATICO
    // Estos atributos no NECESITO CREAR UN OBJETO PARA UTILIZARLOS
    // Estos objetos se pueden llamar desde una clase DIRECTAMENTE
    static Singleton instance_;
    string* greeting_ = nullptr;

public:
    /// LOS CONSTRUCTORES DE TIPO COPIA, LOS DESHABILITA TOTALMENTE COLANDOLE "delete"
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
    ~Singleton() { delete greeting_; }
    // Constructor artificial
    static Singleton& get_instance() { return instance_; }
    // Metodos de instancia o de objeto
    void set_saludo(const string& value) { *greeting_ = value; }
    string get_saludo() { return *greeting_; }
};

Singleton Singleton::instance_;

int main(){




    return 0;
}