//
// Created by Jesus on 22/01/2023.
//

#include "Polinomio.h"

Polinomio::Polinomio(int grade_) {
    grade = grade_;
    random_device rd;
    uniform_int_distribution<int> dis(-2,2);
    coef = new int[grade+1];
    for (int i = 0; i <= grade; ++i) {
        coef[i] = dis(rd);
    }

}

Polinomio::Polinomio(const Polinomio &other) {
    grade = other.grade;
    coef = new int[grade+1];
    for (int i = 0; i <= other.grade; ++i) {
        coef[i] = other.coef[i];
    }
}

ostream &operator<<(ostream &os, const Polinomio &other) {
    int temp = 1;
    if (other.coef[other.grade] != 0 && other.coef[other.grade] != 1  && other.coef[other.grade] != -1){
        os << other.coef[other.grade] << "x" << other.grade;
    }
    else if (other.coef[other.grade] == 1){
        os << "x" << other.grade;
    }
    else if (other.coef[other.grade] == -1){
        os << "-x" << other.grade;
    }

    else{
        for (int i = other.grade-1; i >= 0 ; --i) {
            temp += 1;
            if (other.coef[i] != 0 && other.coef[i] != 1){
                os << other.coef[i] << "x" << i;
                break;
            }
            else if (other.coef[i] == 1){
                os << "x" << i;
                break;
            }
            else if (other.coef[i] == -1){
                os << "-x" << i;
                break;
            }
        }
    }

    for (int i = other.grade-temp; i > -1; --i) {
        if ((other.coef[i] > 1 or other.coef[i] < -1) && i > 1){
            os << " " << Polinomio::signo(other.coef[i])<<" "<<abs(other.coef[i]) << "x" <<  i;
        }
        else if (i == 0 && other.coef[i] != 0){
            os << " " << Polinomio::signo(other.coef[i])<<" "<<abs(other.coef[i]);
        }
        else if (i==1 && (other.coef[i]>1 or other.coef[i]<-1)){
            os << " " << Polinomio::signo(other.coef[i])<<" "<<abs(other.coef[i]) << "x";
        }
        else if ((other.coef[i] == 1 or other.coef[i] == -1) && i==1){
            os << " " << Polinomio::signo(other.coef[i])<<" "<< "x";
        }
        else if ((other.coef[i] == 1 or other.coef[i] == -1) && i>1){
            os << " " << Polinomio::signo(other.coef[i])<<" "<< "x" <<i;
        }
        else{
            if (i != 0 && other.coef[i] != 0){
                os << " " << Polinomio::signo(other.coef[i])<<" "<<abs(other.coef[i]) << "x"<<i;
            }
        }
    }
    os << endl;
    return os;
}

char Polinomio::signo(int x) {
    if (x>0){
        return char(43);
    }
    return char(45);
}

Polinomio Polinomio::operator+(const Polinomio &other) {
    int menor;
    if (this->grade > other.grade){
        menor = other.grade;
    }
    else{
        menor = grade;
    }
    Polinomio ob = other;
    for (int i = menor; i >= 0; --i) {
        ob.coef[i] = other.coef[i] + coef[i];
    }
    return ob;
}

void Polinomio::get_valores() {
    for (int i = 0; i <= grade; ++i) {
        cout << coef[i] << " ";
    }
}

Polinomio::~Polinomio() {
    delete[] coef;
}



