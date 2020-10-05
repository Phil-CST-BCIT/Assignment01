//
// Created by Phil Teng on 2020-09-24.
//

#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP
#include <vector>
using namespace std;

class Matrix{
private:
    size_t row_size;
    size_t col_size;
    vector<vector<double>> *mtx;

public:
    Matrix();
    explicit Matrix(size_t);

    size_t get_r() const {return row_size;}
    size_t get_c() const {return col_size;}
    vector<vector<double>>* get_mtx() {return mtx;}

    ~Matrix(){delete mtx;}
};

#endif //ASSIGNMENT01_MATRIX_HPP
