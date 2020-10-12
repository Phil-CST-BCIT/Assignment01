#include <iostream>
#include <cmath>
#include <iomanip>
#include "matrix.hpp"
#include "connectivity_matrix.hpp"
#include "importance_matrix.hpp"
#include "stochatic_matrix.hpp"
#include "helper.hpp"

using namespace std;

void markov_process(Matrix& transition) {

    constexpr int number_iteration {10};
    constexpr size_t n {4};

    // instantiate a 4 by 1 matrix as the rank matrix
    Matrix rank {n, 1};

    for(size_t i {0}; i < rank.get_r(); ++i) {
        for(size_t j {0}; j < rank.get_c(); ++j) {
            rank.set_value(i,j, 1.0);
        }
    }

    cout << rank << endl;

    Matrix markov {n,1};

    for(int i {0}; i < number_iteration; ++i) {
        markov = transition * rank;
        rank = markov;
    }

    cout << markov << endl;

    double sum {};

    for(int k {}; k < n; ++k) {
        sum = markov.get_value(k, 0) + sum;
    }

    cout << "Result: " << std::setprecision(n) << fixed << endl;
    for(int x {}; x < n; ++x) {
        cout << "rank " << x << " - " << markov.get_value(x, 0) / sum << endl;
    }

}

int main() {

    //================ constants ======================//
    constexpr size_t n {4};
    const string filename {"../connectivity.txt"};
    constexpr double teleport_probability {0.25};

    //================ read file and instantiate connectivity ======//
    string content = read_in(filename);
    vector<double>* v = str_to_vec(content);
    ConnectivityMatrix cm {n, *v};

    cout << cm << endl;

    //=============== calculate importance =====================//
    vector<double> impt {cm.calc_impt()};

    //=============== instantiate importance ==================//
    ImportanceMatrix imptm {n,*v, impt};
    int j {imptm.find_isolate()};

    //=============== normalize the importance matrix ==========//
    imptm.normalize(j);

    cout << imptm << endl;

    //=============== instantiate stochatic matrix ===========//
    StochasticMatrix stom {n, *v, impt};

    stom.random_walk();

    cout << stom << endl;

    //=============== instantiate teleport probability matrix =======//
    vector<double> tele_source(pow(n, 2), teleport_probability);

    Matrix tele_mtx {n, tele_source};

    cout << tele_mtx << endl;

    tele_mtx.multiply(1 - stom.get_p());

    cout << tele_mtx << endl;

    //=============== add normalized matrix and teleport matrix =========//

    Matrix transition {stom + tele_mtx};

    cout << transition << endl;

    //=============== Markov process =============//

    markov_process(transition);

    delete v;

    return 0;
}
