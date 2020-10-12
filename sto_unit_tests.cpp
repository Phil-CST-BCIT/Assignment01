////
//// Created by Phil Teng on 2020-10-11.
////
//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "matrix.hpp"
//#include "importance_matrix.hpp"
//#include "helper.hpp"
//#include "catch.hpp"
//#include "stochatic_matrix.hpp"
//
//TEST_CASE("instantiate a stoch matrix", "instantiation_tag1") {
//
//    string content = read_in("../connectivity.txt");
//    vector<double>* v = str_to_vec(content);
//    size_t n {4};
//    ConnectivityMatrix cm {n, *v};
//
//    vector<double> impt {cm.calc_impt()};
//
//    ImportanceMatrix imptm {n,*v, impt};
//
//    StochasticMatrix tester{n, *v, impt};
//
//    const double rand = static_cast<double>(1.0/tester.get_r());
//
//    REQUIRE((tester.get_mtx()->at(0).at(3) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(1).at(3) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(2).at(3) - rand < 0.001) == true);
//    REQUIRE((tester.get_mtx()->at(3).at(3) - rand < 0.001) == true);
//
//}
//
//TEST_CASE("randome walk", "instantiation_tag2") {
//
//    string content = read_in("../connectivity.txt");
//    vector<double>* v = str_to_vec(content);
//    size_t n {4};
//    ConnectivityMatrix cm {n, *v};
//
//    vector<double> impt {cm.calc_impt()};
//
//    ImportanceMatrix imptm {n,*v, impt};
//
//    StochasticMatrix tester{n, *v, impt};
//
//    const double rand = static_cast<double>(1.0/tester.get_r());
//
//    tester.random_walk();
//
//    REQUIRE((tester.get_mtx()->at(0).at(3) == 0) == true);
//    REQUIRE((tester.get_mtx()->at(1).at(3) - 0.425 < 0.001) == true);
//
//}