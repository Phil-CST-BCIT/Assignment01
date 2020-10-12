//
// Created by Phil Teng on 2020-10-11.
//

#ifndef ASSIGNMENT01_IMPORTANCE_MATRIX_HPP
#define ASSIGNMENT01_IMPORTANCE_MATRIX_HPP
#include "connectivity_matrix.hpp"

class ImportanceMatrix : public Matrix{
public:
    ImportanceMatrix(size_t, vector<double>&,vector<double>&);
    int find_isolate();
    void normalize(int index);
};
#endif //ASSIGNMENT01_IMPORTANCE_MATRIX_HPP
