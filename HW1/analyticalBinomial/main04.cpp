#include "binModel01.h"
#include "options01.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S0, U, D, R, K;
    int N;

    // Get input data
    getInputData(&S0, &U, &D, &R);

    // Get input for N and K
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;

    // Output the results
    cout << "Binomial Tree Call: " << PriceByCRR(S0, U, D, R, N, K, CallPayoff) << endl;
    cout << "Analytic Call: " << PriceAnalytic(S0, U, D, R, N, K, CallPayoff) << endl;
    cout << "Binomial Tree Put: " << PriceByCRR(S0, U, D, R, N, K, PutPayoff) << endl;
    cout << "Analytic Put: " << PriceAnalytic(S0, U, D, R, N, K, PutPayoff) << endl;
    

    return 0;
}