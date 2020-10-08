#include <iostream>

#include "matrix.hpp"
using namespace std;

void fill_vec(Matrix& mtx) {
        for(vector<double> &vec: *(mtx.get_mtx())) {
        for(double & j : vec) {
            j = 1.0 + 0.9;
        }
    }
}

int main() {

    Matrix test1 {2};
    fill_vec(test1);

    Matrix test2 {};

    test2 = test1;


    cout << test2 << endl;

//    cout << test.get_r() << endl;
//    cout << test.get_mtx()->at(0).at(0) << endl;
//
//    cout << test;

//    test.clear();
//
//    cout << test.get_mtx()->at(0).at(0) << endl;

    return 0;
}
