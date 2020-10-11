//
// Created by Phil Teng on 2020-10-11.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "matrix.hpp"
#include "connectivity_matrix.hpp"
#include "helper.hpp"
#include "catch.hpp"

//TEST_CASE("read in a file", "input_tag1") {
//    bool tester = read_in("../connectivity.txt");
//
//    REQUIRE(tester == true);
//}
//
//TEST_CASE("parse string to vector", "input_tag2"){
//    string content = read_in("../connectivity.txt");
//
//    vector<double>* tester = str_to_vec(content);
//
//    REQUIRE(tester->at(0) == 0);
//
//    delete tester;
//}
//
//TEST_CASE("instantiate a connectivity matrix with all 0s", "instantiation_tag1") {
//    string content = read_in("../connectivity.txt");
//    vector<double>* v = str_to_vec(content);
//    size_t n {4};
//    ConnectivityMatrix tester {n, *v};
//    delete v;
//
//    cout << tester;
//
//    REQUIRE(tester.get_r() == 4);
//    REQUIRE(tester.get_c() == 4);
//
//    REQUIRE(tester.get_value(0,0) == 0);
//    REQUIRE(tester.get_value(0,1) == 1);
//    REQUIRE(tester.get_value(0,2) == 1);
//    REQUIRE(tester.get_value(0,3) == 0);
//
//}

TEST_CASE("calculate the importance of the default matrix", "func_tag1") {
    string content = read_in("../connectivity.txt");
    vector<double>* v = str_to_vec(content);
    size_t n {4};
    ConnectivityMatrix tester {n, *v};
    delete v;

    vector<double> impt {tester.calc_impt()};

    REQUIRE(impt.at(0) == 2);
    REQUIRE(impt.at(1) == 2);
    REQUIRE(impt.at(2) == 2);
    REQUIRE(impt.at(3) == 0);

}