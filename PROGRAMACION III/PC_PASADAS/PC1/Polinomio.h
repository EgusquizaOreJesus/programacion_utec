//
// Created by Jesus on 22/01/2023.
//

#ifndef PC1_POLINOMIO_H
#define PC1_POLINOMIO_H
#include "iostream"
#include "random"

using namespace std;

class Polinomio {
    int* coef = nullptr;
    int grade = int {};
    static char signo(int x);
public:
    explicit Polinomio(int grade_);
    Polinomio(const Polinomio& other);

    ~Polinomio();

    friend ostream& operator<<(ostream& os, const Polinomio& other);
    Polinomio operator+(const Polinomio& other);

    void get_valores();
};


#endif //PC1_POLINOMIO_H
