//
// Created by Phil Teng on 2020-10-11.
//
#include <iostream>
#include "importance_matrix.hpp"
using namespace std;
//constructor: instantiates ImportanceMatrix for entries non-zero
ImportanceMatrix::ImportanceMatrix(size_t n,vector<double>& source ,vector<double>& impt)
                :Matrix(n, source) {
    for(size_t j = 0; j < this->get_c(); ++j) {
        for(size_t i = 0; i < this->get_r(); ++i) {
            if(impt.at(j) != 0) {
                this->get_mtx()->at(j).at(i) = this->get_mtx()->at(j).at(i) / impt.at(j);
            }
        }
    }
}

//member method: assume there is only one isolate webpage. found return the column index.
int ImportanceMatrix::find_isolate() {

    for(size_t j = 0; j < this->get_c(); ++j) {
        int counter {};
        for(size_t i = 0; i < this->get_r(); ++i) {
            if(this->get_mtx()->at(j).at(i) == 0) {
                ++counter;
            }
        }

        if(counter == this->get_r()) {
            return j;
        }
    }

    return -1;
}

//member method: normalize the importance matrix
void ImportanceMatrix::normalize(int index) {
    double r = this->get_r();
    const double randomness = 1.0/r;

    for(int i {0}; i < this->get_r(); ++i) {
        this->get_mtx()->at(index).at(i) = randomness;
    }
}
