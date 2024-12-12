//
// Created by Jesus on 20/01/2023.
//

#ifndef CLASE_3_FUNCTION1_H
#define CLASE_3_FUNCTION1_H
#include "iostream"
#include "vector"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using INT_NO_NEGATIVE = size_t;

INT_NO_NEGATIVE * crear_array(int size);

vector<INT_NO_NEGATIVE> crear_Vector(int size);

void print_array(INT_NO_NEGATIVE* arr, int size);

void print_vector(const vector<INT_NO_NEGATIVE> &vec);

INT_NO_NEGATIVE find_mode_array(const INT_NO_NEGATIVE* arr, int size);

INT_NO_NEGATIVE find_mode_vec(const vector<INT_NO_NEGATIVE> &vec);

void insertion_sort_vector(vector<INT_NO_NEGATIVE> &arr);

void insertion_sort_array(INT_NO_NEGATIVE* arr, int size);

#endif //CLASE_3_FUNCTION1_H
