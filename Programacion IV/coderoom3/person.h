//
// Created by Jesus Egusquiza on 5/4/2023.
//

#ifndef CODEROOM3_PERSON_H
#define CODEROOM3_PERSON_H
#include <iostream>
#include <utility>

using namespace std;

struct Person
{
    string nombre;
    int edad{};
    Person(){
    }
    Person(string nombre_,int edad_){
        nombre = std::move(nombre_);
        edad = edad_;
    }
    explicit Person(string nombre_){
        nombre = std::move(nombre_);
    }
    friend bool operator<(const Person& A, const Person& B);
    friend bool operator>(const Person& A, const Person& B);
    friend ostream& operator<<(ostream& os, const Person& A);
    friend bool operator==(const Person& A, const Person& B);

};

bool operator<(const Person& A, const Person& B){
    return A.nombre < B.nombre;
}
bool operator>(const Person& A, const Person& B){
    return A.nombre > B.nombre;
}
ostream& operator<<(ostream& os, const Person& A){
    os << "("<<A.nombre << ", " << A.edad <<")";
    return os;
}
bool operator==(const Person& A, const Person& B){
    return A.nombre == B.nombre;
}
#endif //CODEROOM3_PERSON_H
