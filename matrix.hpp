//
// Created by Phil Teng on 2020-09-24.
//

#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP
#include <vector>
using namespace std;

class Matrix{

    friend ostream& operator<<(ostream& out, const Matrix&);

    friend void mtx_swap(Matrix&, Matrix&);

private:
    size_t row_size;
    size_t col_size;
    vector<vector<double>> *mtx;

public:
    //constructors
    Matrix();
    explicit Matrix(size_t);
    Matrix(size_t, size_t);
    Matrix(size_t n, vector<double>&);

    //copy constructor
    Matrix(const Matrix& source);

    //assignment operator
    Matrix& operator=(Matrix rhs);

    //getters
    size_t get_r() const {return row_size;}
    size_t get_c() const {return col_size;}
    double get_value(size_t, size_t)const;
    vector<vector<double>>* get_mtx() {return mtx;}

    //setters
    void set_value(size_t, size_t, double);
    void set_r(size_t r){this->row_size = r;}
    void set_c(size_t c){this->col_size = c;}

    //operator overloading as member methods
    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;

    Matrix& operator++(); //prefix
    Matrix operator++(int); //postfix

    Matrix& operator--();
    Matrix operator--(int);

    //Other functionalities
    bool clear();


    ~Matrix(){delete mtx;}
};

#endif //ASSIGNMENT01_MATRIX_HPP
