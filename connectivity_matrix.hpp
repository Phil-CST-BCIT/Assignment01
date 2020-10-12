//
// Created by Phil Teng on 2020-10-11.
//

#ifndef ASSIGNMENT01_CONNECTIVITY_MATRIX_HPP
#define ASSIGNMENT01_CONNECTIVITY_MATRIX_HPP
#include <string>
#include "matrix.hpp"

class ConnectivityMatrix :public Matrix{

public:

    ConnectivityMatrix(size_t n, vector<double>);

    vector<double> calc_impt();


    ~ConnectivityMatrix(){};
};




#endif //ASSIGNMENT01_CONNECTIVITY_MATRIX_HPP
