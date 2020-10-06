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
    Matrix(size_t, size_t);
    Matrix(size_t n, vector<double>&);

    size_t get_r() const {return row_size;}
    size_t get_c() const {return col_size;}
    double get_value(size_t, size_t)const;
    vector<vector<double>>* get_mtx() {return mtx;}

    void set_value(size_t, size_t, double);
    void set_r(size_t r){this->row_size = r;}
    void set_c(size_t c){this->col_size = c;}

    bool clear();


    ~Matrix(){delete mtx;}
};

#endif //ASSIGNMENT01_MATRIX_HPP
