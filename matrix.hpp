//
// Created by Phil Teng on 2020-09-24.
//

#ifndef ASSIGNMENT01_MATRIX_HPP
#define ASSIGNMENT01_MATRIX_HPP
#include <vector>
using namespace std;

class Matrix{

    friend ostream& operator<<(ostream& out, const Matrix&);
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs ,const Matrix& rhs);
    friend void assign_to_zero(Matrix*);
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);
    friend void mtx_swap(Matrix&, Matrix&);
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);

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

    Matrix& operator++(); //prefix return by ref
    Matrix operator++(int); //postfix

    Matrix& operator--();
    Matrix operator--(int);

    Matrix& operator+=(const Matrix& rhs);//addition assignment
    Matrix& operator-=(const Matrix& rhs);//subtraction assignment
    Matrix& operator*=(const Matrix& rhs);

    //Other functionalities
    void multiply(double);
    bool clear();


    ~Matrix(){delete mtx;}
};

#endif //ASSIGNMENT01_MATRIX_HPP
