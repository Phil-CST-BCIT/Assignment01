//
// Created by Phil Teng on 2020-09-24.
//
#include <stdexcept>
#include "matrix.hpp"

Matrix::Matrix() :Matrix(1) {}

Matrix::Matrix(size_t n) :row_size{n}, col_size{n}, mtx(new vector<vector<double>>){

    if(n == 0) {
        throw runtime_error("the size of a Matrix must be greater than 0");
    }

    for(size_t i = 0; i < row_size; ++i) {
        mtx->push_back(vector<double>());
        for(size_t j = 0; j < col_size; ++j) {
            mtx->at(i).push_back(0.0);
        }
    }
}