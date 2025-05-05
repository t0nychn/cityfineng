#include <iostream>
#include <cmath>
using namespace std;

#include "binModel01.h"

int main() {
    double S0, U, D, R;
    // get Input data
    if (getInputData(&S0, &U, &D, &R) == 1) // pass in memory address for pointer
        return 1;

    // 1. make sure S0>0, (1+U)>0, (1+D)>0, (1+R)>0, U<D,
    // otherwise interchange U <-> D
    // compute the risk-neutral probability
    double q = riskNeutralProb(U, D, R);
    cout << "Risk-neutral probability q = " << q << endl;
    // compute stock price at n=3, i =2;
    int n = 3;
    int i = 2;
    cout << "S(" << n << ", " << i << ") = " << S(S0, U, D, n, i) << endl;
    char x;
    cin >> x;
    return 0;
}