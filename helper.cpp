//
// Created by Phil Teng on 2020-10-10.
//
#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
#include <vector>
#include <cstring>
#include "helper.hpp"

using namespace std;

//returns true if the difference of two doubles less than epsilon.
bool is_equal(double a, double b) {
    return fabs(a - b) < numeric_limits<double>::epsilon();
}

//input stream: reads the connectivity text file and returns a string
string read_in(const string& path) {

    ifstream in_file;
    string line {};
    string content {};
    in_file.open(path);

    if(!in_file) {
        cerr << "Problem opening file." << endl;
        exit(-1);
    } else {

        while(getline(in_file, line)){
            content += line + " ";
        }

        in_file.close();

        return content;
    }
}

//extracts each 1 or 0 in the string and returns a vector as a container
vector<double>* str_to_vec(const string& content) {

    char buffer[content.length() + 1];

    std::size_t length = content.copy(buffer,content.length(),0);

    buffer[length]='\0';

    char* ptr = buffer;

    vector<double>* vec = new vector<double>;

    for(size_t i = 0; i < content.length(); ++i) {
        if(*ptr != ' ') {
            int entry = atoi(ptr);
            vec->push_back(entry);
        }
        ++ptr;
    }

    return vec;
}

