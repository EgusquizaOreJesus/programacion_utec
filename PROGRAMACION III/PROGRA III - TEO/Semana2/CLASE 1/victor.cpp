//
// Created by Jesus on 21/01/2023.
//

#include "victor.h"

victor::victor(size_t size) {
    size_ = size;
    random_device rd;
    uniform_int_distribution<int> dis(0,99);
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = dis(rd);
    }
}

victor::victor(const victor &other) {   // copiar el contenido del otro en el actual (this)
    // copio el tamaño
    size_ = other.size_;
    // copia el contenido de data
    // OBS NO ES CORRECTO QUE PONGAS: data_ = other.data_
    // NECESITAS PRIMERO RESERVAR EL ESPACIO DE MEMORIA YA QUE NO ES CORRECTO COPIAR ASI UNA MEMORIA DINAMICA
    data = new int[size_];
    // ahora copias cada elemento del contenido
    // para copiar cada elemento del contenido puedes usar un for, o la funcion "copy"
    // con un for seria:
    /*
    for (int i = 0; i < size_; ++i) {
        data[i] = other.data[i];
    }
     */
    // con la funcion copy seria:
    copy(other.data,other.data + size_, data);
}

victor::victor(victor &&other)  noexcept {    //Mover el contenido de otro en el actual(this)
    size_ = other.size_;
    data = other.data;   //Copia la referencia de la data en el nuevo victor
    // Pero luego IMPORTANTE
    // TIENES DE QUE HACER LA DESHABILITACION DEL other, porque todo se movio al actual (this)
    // other tiene que quedar vacio, other ya no tiene que acceder a el
    // Para deshabilitarlo haces:
    other.size_ = int {};
    other.data = nullptr;
}

// EN EL CASO DE ESTOS CONSTRUCTOR NO EXISITIA LA CLASE EN LA QUE SE VA COPIAR EL OTHER O SE VA MOVER EL OTHER NO EXISTIAN
// ESTABAN VACIAS

// PERO EN EL CASO DE SUS OPERADORES DE ASIGNACION DE COPIA Y MOVE TENGO QUE ASEGURARME DE QUE NO ME ESTE AUTO REFERENCIANDO
// NECESITO VERIFICAR QUE LA DIRECCION DE OTHER NO COINCIDE CON EL ACTUAL, PARA NO COPIAR LA MISMA CLASE

victor &victor::operator=(const victor &other) {
    if (this == &other){return *this;}
    // Ya una vez verificado que no son la misma direccion. hago el mismo proceso que el constructor
    size_ = other.size_;
    //OBS: HAY QUE TENER CUIDADO, PORQUE EN ESTE CASO
    // ya EXISTE UNA CLASE ACTUAL VICTOR, Y UN OTHER, AMBOS EXISTEN
    // ENTONCES ANTES DE COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL,
    // PRIMERO TENGO QUE LIBERAR SU MEMORIA DEL ACTUAL, PARA EVITAR ERRORES
    delete[] data;  // LIBERO SU MEMORIA PARA LUEGO PODER RESERVAR MEMORIA PARA COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL
    data = new int[size_];
    copy(other.data,other.data + size_, data);
    return *this;
}

victor &victor::operator=(victor &&other)  noexcept {
    if (this == &other){return *this;}
    delete[] data;
    size_ = other.size_;
    data = other.data;
    //OBS: HAY QUE TENER CUIDADO, PORQUE EN ESTE CASO
    // ya EXISTE UNA CLASE ACTUAL VICTOR, Y UN OTHER, AMBOS EXISTEN
    // ENTONCES ANTES DE COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL,
    // PRIMERO TENGO QUE LIBERAR SU MEMORIA DEL ACTUAL, PARA EVITAR ERRORES
    other.size_ = int {};
    other.data = nullptr;
    return *this;
}

// cual es la diferencia entre un constructor copia y un move
// EN UN COPY:
// TENGO QUE COPIAR EL CONTENIDO DEL OTRO EN EL ACTUAL

// EN UN MOVE:
// NO ES COPIAR, ES MOVER EL CONTENIDO DE OTRO EN EL ACTUAL (this)
ostream &operator<<(ostream &os, const victor &v1) {
    for (int i = 0; i < v1.size_; ++i) {
        os << v1.data[i] << " ";
    }
    os << endl;
    return os;
}

victor::~victor() {
    delete[] data;
}
