//
// Created by Phil Teng on 2020-10-10.
//

#ifndef ASSIGNMENT01_HELPER_HPP
#define ASSIGNMENT01_HELPER_HPP
#include <string>
#include "matrix.hpp"
using namespace std;

bool is_equal(double a, double b);

string read_in(const string&);

vector<double>* str_to_vec(const string&);

void set_entries(Matrix&);

#endif //ASSIGNMENT01_HELPER_HPP
