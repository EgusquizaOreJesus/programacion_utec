#include <iostream>

// PARAMETRO TEMPLATE SIN TIPO
// TENEMOS 4:
// 1. Type name(opcional)
// 2. Type name(opcional) = default
// 3. Type... name(opcional)
// 4. placeholder name


// PARAMETRO TEMPLATE CON TIPO
//  Tenemos 3:
//  1. type-parameter-key name(opcional)
//  2. type-parameter-key name(opcional) = default
//  3. type-parameter-key...name(opcional)

// PARAMETRO TEMPLATE DE TEMPLATE
// Tenemos 3:
//  1. template<parameter-list> type-parameter-key name(opcional)
//  2. template<parameter-list> type-parameter-key name(opcional) = default
//  3. template<parameter-list> type-parameter-key...name(opcional)


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
