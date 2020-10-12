//
// Created by Phil Teng on 2020-10-11.
//

#ifndef ASSIGNMENT01_STOCHATIC_MATRIX_HPP
#define ASSIGNMENT01_STOCHATIC_MATRIX_HPP
#include "importance_matrix.hpp"

class StochasticMatrix : public ImportanceMatrix{
private:
    double p {0.85};
public:
    StochasticMatrix(size_t, vector<double>&,vector<double>&);

    double get_p() const {return p;}

    void random_walk();



};

#endif //ASSIGNMENT01_STOCHATIC_MATRIX_HPP
