//
// Created by Phil Teng on 2020-10-11.
//

#include <iostream>
#include "connectivity_matrix.hpp"

using namespace std;

//constructor: instantiate a n by n connectivity matrix with entries from source
ConnectivityMatrix::ConnectivityMatrix(size_t n, vector<double> source)
                :Matrix(n, source){
    for(double d : source) {
        if(d != 0 && d != 1) {
            cerr << "instantiation problem: connectivity either 0 or 1" <<endl;
            exit(1);
        }
    }
}

//member method: calculate the importance of a connectivity matrix
vector<double> ConnectivityMatrix::calc_impt() {

    vector<double> impt {};

    for(size_t j = 0; j < this->get_c(); ++j) {
        double entry {};
        for(size_t i = 0; i < this->get_r(); ++i) {
            entry += this->get_mtx()->at(j).at(i);
        }
        impt.push_back(entry);
    }

    return impt;
}

