#include <iostream>
using namespace std;

typedef enum GlTheme {
    THEME_POCKET_GB = -1,
    THEME_RUSTIC_GB = 0,
    THEME_MIST_GB,
    THEME_CRIMSON_GB,
} GlTheme;
typedef enum OptionItems {
    ITEM_PTOS = 0,
    ITEM_THEME ,
    ITEM_GAME_MODE,
    ITEM_FULLSCREEN,
} OptionItems;

static GlTheme internalTheme = static_cast<GlTheme>(-1);

int* sumar(){
    int x = 2;
    int* ptr = &x;
    cout << "hola";
    return ptr;
}

void print(){
    cout << "print" << endl;
}

class A{
protected:
    int edad;
    public:
    int get_edad(){
        return edad;
    }
    friend void print();
};

class B:public A{
    public:
    int get_b(){
        edad;
        get_edad();
        print();
    }
};
int main() {
    GlTheme temas = THEME_MIST_GB;
    cout << temas;
    temas = static_cast<GlTheme>(temas - 1);
    cout << temas;
    return 0;
}