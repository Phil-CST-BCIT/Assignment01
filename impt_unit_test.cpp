////
//// Created by Phil Teng on 2020-10-11.
////
//
//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "matrix.hpp"
//#include "importance_matrix.hpp"
//#include "helper.hpp"
//#include "catch.hpp"
//
//
////TEST_CASE("instantiate a new impt matrix", "instantiation_tag1") {
////
////    string content = read_in("../connectivity.txt");
////    vector<double>* v = str_to_vec(content);
////    size_t n {4};
////    ConnectivityMatrix cm {n, *v};
////
////    vector<double> impt {cm.calc_impt()};
////
////    ImportanceMatrix tester {n,*v, impt};
////
////    REQUIRE(tester.get_r() == 4);
////    REQUIRE(tester.get_c() == 4);
////    REQUIRE(tester.get_value(0, 0) == 0);
////    REQUIRE((tester.get_value(0, 1) - 0.5 < 0.01) == true);
////    REQUIRE((tester.get_value(0, 2) - 0.5 < 0.01) == true);
////    REQUIRE(tester.get_value(0, 3) == 0);
////
////    REQUIRE((tester.get_value(3, 0) - 0.5 < 0.01) == true);
////    REQUIRE((tester.get_value(3, 1) - 0.5 < 0.01) == true);
////    REQUIRE(tester.get_value(3, 2) == 0);
////    REQUIRE(tester.get_value(3, 3) == 0);
////    delete v;
////}
//
////TEST_CASE("find isolate index", "functionality_tag1") {
////    string content = read_in("../connectivity.txt");
////    vector<double>* v = str_to_vec(content);
////    size_t n {4};
////    ConnectivityMatrix cm {n, *v};
////
////    vector<double> impt {cm.calc_impt()};
////
////    ImportanceMatrix tester {n,*v, impt};
////
////    int j {tester.find_isolate()};
////
////    REQUIRE(j == 3);
////}
//
//TEST_CASE("add randomness", "functionality_tag2") {
//    string content = read_in("../connectivity.txt");
//    vector<double>* v = str_to_vec(content);
//    size_t n {4};
//    ConnectivityMatrix cm {n, *v};
//
//    vector<double> impt {cm.calc_impt()};
//
//    ImportanceMatrix tester {n,*v, impt};
//
//    int j {tester.find_isolate()};
//
//    tester.normalize(j);
//
//    const double rand = static_cast<double>(1.0/tester.get_r());
//
//    REQUIRE((tester.get_mtx()->at(0).at(j) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(1).at(j) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(2).at(j) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(3).at(j) - rand < 0.001) == true);
//
//}