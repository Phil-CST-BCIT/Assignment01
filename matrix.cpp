//
// Created by Phil Teng on 2020-09-24.
//

#include <iostream>
#include <stdexcept>
#include "matrix.hpp"
#include "helper.hpp"

using namespace std;

//friend function: overload the insertion operator. It prints out a matrix
ostream& operator<<(ostream& out, const Matrix& rhs){
    out << "Size of the Matrix: " << rhs.get_r() << " * " << rhs.get_c() << endl;

    for(size_t i = 0; i < rhs.get_r(); ++i) {
        out << "| ";
        for(size_t j = 0; j < rhs.get_c(); ++j) {
            out << rhs.mtx->at(i).at(j) << " ";
        }
        out << "|\n";
    }

    return out;
}

//friend function: overload the equality operator. It returns ture if two matrices are same in size and entries.
bool operator==(const Matrix &lhs, const Matrix& rhs)  {
    if(lhs.get_r() != rhs.get_r() || rhs.get_c() != rhs.get_c())
        return false;

    for(size_t i = 0; i < lhs.get_r(); ++i) {
        for(size_t j = 0; j < lhs.get_c(); ++j) {
            if(!is_equal(lhs.mtx->at(i).at(j), rhs.mtx->at(i).at(j)))
                return false;
        }
    }
    return true;
}

//friend function: overload the inequality operator. Returns false if two matrices are equal.
bool operator!=(const Matrix& lhs,const Matrix &rhs)  {
    return ! (lhs == rhs);
}

//friend function: initializes entries to zero when matrix constructors being called.
void assign_to_zero(Matrix* mtx) {
    for(size_t i = 0; i < mtx->get_r(); ++i) {
        mtx->get_mtx()->push_back(vector<double>());
        for(size_t j = 0; j < mtx->get_c(); ++j) {
             mtx->mtx->at(i).push_back(0.0);
        }
    }
}

//friend function: swap size and entries of matrix lhs and matrix rhs.
void mtx_swap(Matrix& lhs, Matrix &rhs) {
    swap(lhs.row_size, rhs.row_size);
    swap(lhs.col_size, rhs.col_size);
//    lhs.row_size = rhs.row_size;
//    lhs.col_size = rhs.col_size;
    swap(lhs.mtx, rhs.mtx);
}

//friend function: add two matrices and return the sum
Matrix operator+(Matrix lhs, const Matrix& rhs){
    lhs += rhs;
    return lhs;
}

//friend function: subtract two matrices and return the difference
Matrix operator-(Matrix lhs, const Matrix& rhs){
    lhs -= rhs;
    return lhs;
}

//friend function: multiply two matrices and return the product
Matrix operator*(Matrix lhs, const Matrix& rhs) {
    lhs *= rhs;
    return lhs;
}


//default constructor
Matrix::Matrix() :Matrix(1) {}

//constructor: instantiate a n by n matrix
//throws exception when n is zero
Matrix::Matrix(size_t n) :row_size{n}, col_size{n}, mtx(new vector<vector<double>>){

    if(n == 0)
        throw runtime_error("the size of a Matrix must be greater than 0");

    assign_to_zero(this);

}

//constructor: instantiate a matrix with r rows and c columns
//throws exception when r or c is zero
Matrix::Matrix(size_t r, size_t c)
    :row_size{r}, col_size{c}, mtx(new vector<vector<double>>) {

    if(r == 0 || c == 0)
        throw runtime_error("the size of a Matrix must be greater than 0");

    assign_to_zero(this);

}

//constructor: instantiate a n by n matrix and assign each entry from source to the matrix
Matrix::Matrix(size_t n, vector<double> & source) :Matrix(n) {

    if(source.size() != n*n)
        throw runtime_error("the size of the source must be an integer to power of 2");

    int pos = 0;
    for(size_t i = 0; i < this->row_size; ++i) {
        mtx->push_back(vector<double>());
        for(size_t j = 0; j < this->col_size; ++j) {
            mtx->at(i).at(j) = source.at(pos);
            pos++;
        }
    }
}

//copy constructor
Matrix::Matrix(const Matrix &source)
    :Matrix(source.get_r(), source.get_c()){
    for(int i = 0; i < this->get_r(); ++i) {
        for(int j = 0; j < this->get_c(); ++j) {
            this->mtx->at(i).at(j) = source.mtx->at(i).at(j);
        }
    }
}

//assignment operator
Matrix& Matrix::operator=(Matrix rhs) {
    if(*this == rhs) {
        return *this;
    }

    mtx_swap(*this, rhs);

    return *this;
}

//member method: get the entry in a specified row and column
double Matrix::get_value(size_t row, size_t col) const {

    if(row > this->get_r() || col > this->get_c())
        throw runtime_error("out of range");

    return (this->mtx)->at(row).at(col);
}

//member method: set a entry to a specified row and column.
void Matrix::set_value(size_t row, size_t col, double value) {

    if(row > this->get_r() || col > this->get_c())
        throw runtime_error("out of range");


    (this->get_mtx())->at(row).at(col) = value;
}

//member method: overload the prefix increment operator
Matrix& Matrix::operator++() {
    for(vector<double>& vec : *(this->mtx)) {
        for(double& v : vec) {
            ++v;
        }
    }
    return *this;
}

//member method: overload the postfix increment operator
Matrix Matrix::operator++(int) {
    const Matrix cp {*this};

    this->operator++();

    return cp;
}

//member method: overload the prefix decrement operator
Matrix& Matrix::operator--() {
    for(vector<double>& vec : *(this->mtx)) {
        for(double& v : vec) {
            --v;
        }
    }

    return *this;
}

//member method: overload the postfix decrement operator
Matrix Matrix::operator--(int) {
    Matrix cp {*this};

    this->operator--();

    return cp;
}

//member method: overload addition assignment operator
Matrix& Matrix::operator+=(const Matrix& rhs) {
    if((rhs.get_r() != this->get_r()) || (rhs.get_c() != this->get_c()))
        throw runtime_error("the size of two matrices must equal");

    for(int i = 0; i < this->get_r() && i < rhs.get_r(); ++i) {
        for(int j = 0; j < this->get_c() && j < rhs.get_c(); ++j) {
            this->mtx->at(i).at(j) = this->mtx->at(i).at(j) + rhs.mtx->at(i).at(j);
        }
    }

    return *this;
}

//member method: overload substraction assignment operator
Matrix& Matrix::operator-=(const Matrix &rhs) {
    if((rhs.get_r() != this->get_r()) || (rhs.get_c() != this->get_c()))
        throw runtime_error("the size of two matrices must equal");

    for(int i = 0; i < this->get_r() && i < rhs.get_r(); ++i) {
        for(int j = 0; j < this->get_c() && j < rhs.get_c(); ++j) {
            this->mtx->at(i).at(j) = this->mtx->at(i).at(j) - rhs.mtx->at(i).at(j);
        }
    }

    return *this;
}

//member method: two matrices multiplication and assignment
Matrix& Matrix::operator*=(const Matrix &rhs) {
    if(this->get_c() != rhs.get_r())
        throw runtime_error("Matrices multiplication not defined");

    vector<double> source(this->get_r() * rhs.get_c(), 0);

    int counter {0};
    for(int i = 0; i < this->get_r(); ++i) {
        for(int k = 0; k < this->get_r(); ++k) {
            double entry {0.0};
            for(int j = 0; j < rhs.get_r(); ++j) {
                entry = entry + this->mtx->at(i).at(j) * rhs.mtx->at(j).at(k);
            }
            source.at(counter) = entry;
            ++counter;
        }
    }

    Matrix temp {this->get_r(), source};

    *this = temp;
    return *this;
}

//member method: set all entries to zero.
bool Matrix::clear() {
    for(vector<double>& vec: *(this->get_mtx())){
        if(!vec.empty()) {
            for(double &i:vec) {
                i = 0.0;
            }
        }
    }

    for(vector<double> &vec : *(this->get_mtx())) {
        for(double &i : vec) {
            if(i != 0) {
                return false;
            }
        }
    }

    return true;
}








