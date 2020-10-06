//
// Created by Phil Teng on 2020-09-24.
//
#include <stdexcept>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix() :Matrix(1) {}

Matrix::Matrix(size_t n) :row_size{n}, col_size{n}, mtx(new vector<vector<double>>){

    if(n == 0)
        throw runtime_error("the size of a Matrix must be greater than 0");


    for(size_t i = 0; i < this->row_size; ++i) {
        mtx->push_back(vector<double>());
        for(size_t j = 0; j < this->col_size; ++j) {
            mtx->at(i).push_back(0.0);
        }
    }
}

Matrix::Matrix(size_t r, size_t c)
    :row_size{r}, col_size{c}, mtx(new vector<vector<double>>) {

    if(r == 0 || c == 0)
        throw runtime_error("the size of a Matrix must be greater than 0");


    for(size_t i = 0; i < this->row_size; ++i) {
        mtx->push_back(vector<double>());
        for(size_t j = 0; j < this->col_size; ++j) {
            mtx->at(i).push_back(0.0);
        }
    }
}

Matrix::Matrix(size_t n, vector<double> & source) :Matrix(n) {

    if(source.size() != n*n)
        throw runtime_error("the size of the source must be an integer to power of 2");

    for(size_t i = 0; i < this->row_size; ++i) {
        mtx->push_back(vector<double>());
        for(size_t j = 0; j < this->col_size; ++j) {
            mtx->at(i).push_back(source.at(j));
        }
    }
}

double Matrix::get_value(size_t row, size_t col) const {

    if(row > this->get_r() || col > this->get_c())
        throw runtime_error("out of range");

    return (this->mtx)->at(row).at(col);
}

void Matrix::set_value(size_t row, size_t col, double value) {

    if(row > this->get_r() || col > this->get_c())
        throw runtime_error("out of range");


    (this->get_mtx())->at(row).at(col) = value;
}

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








