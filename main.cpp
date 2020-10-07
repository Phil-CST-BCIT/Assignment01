#include <iostream>

#include "matrix.hpp"
using namespace std;

int main() {

    Matrix test {2};

//    for(vector<double> &vec: *(test.get_mtx())) {
//        for(size_t j = 0; j < vec.size(); ++j) {
//            vec.at(j) = 1.0;
//        }
//    }

    cout << test.get_r() << endl;
    cout << test.get_mtx()->at(0).at(0) << endl;

//    test.clear();
//
//    cout << test.get_mtx()->at(0).at(0) << endl;

    return 0;
}
