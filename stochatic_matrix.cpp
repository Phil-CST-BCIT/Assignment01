//
// Created by Phil Teng on 2020-10-11.
//

#include "stochatic_matrix.hpp"


//constructor: instantiate a stochastic matrix
StochasticMatrix::StochasticMatrix(size_t n, vector<double>& source, vector<double>& impt) :
                ImportanceMatrix(n, source, impt){
    int index {this->find_isolate()};
    this->normalize(index);
}

//member method: multiply p {0.85} to every entry of the stochastic matrix
void StochasticMatrix::random_walk() {
    for (size_t i{0}; i < this->get_r(); ++i) {
        for (size_t j{0}; j < this->get_c(); ++j) {
            double entry{this->get_mtx()->at(i).at(j)};
            this->get_mtx()->at(i).at(j) = entry * this->p;
        }
    }
}
