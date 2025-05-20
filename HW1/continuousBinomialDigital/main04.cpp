#include "binModel01.h"
#include "options01.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S0, U, D, R, K;
    int N;
    double deltaT;

    // Get input data
    getInputData(&S0, &U, &D, &R, &N, &deltaT);

    // Get input for N and K
    cout << "Enter K: ";
    cin >> K;

    double analyticCallPrice = PriceAnalytic(S0, U, D, R, N, K, CallPayoff); // save for later
    // Output the results
    cout << "Binomial Tree Call: " << PriceByCRR(S0, U, D, R, N, K, CallPayoff) << endl;
    cout << "Analytic Call: " << analyticCallPrice << endl;
    cout << "Binomial Tree Put: " << PriceByCRR(S0, U, D, R, N, K, PutPayoff) << endl;
    cout << "Analytic Put: " << PriceAnalytic(S0, U, D, R, N, K, PutPayoff) << endl;

    // Initialise the bump for finite diff
    double epsilon = 0.01;

    double deltaCall = (PriceAnalytic(S0 + epsilon, U, D, R, N, K, CallPayoff) - PriceAnalytic(S0 - epsilon, U, D, R, N, K, CallPayoff)) / (2 * epsilon); // via finite diff for digital ATM delta
    double deltaPut = (PriceAnalytic(S0 + epsilon, U, D, R, N, K, PutPayoff) - PriceAnalytic(S0 - epsilon, U, D, R, N, K, PutPayoff)) / (2 * epsilon);

    // Bump U, D by sigma + epsilon (not the best most modular implementation and assumes CRR)
    double Ue = U * exp(epsilon * sqrt(deltaT));
    double De = D * exp(-epsilon * sqrt(deltaT));

    // call and put should have same vega by put-call parity
    double vega = (PriceAnalytic(S0, Ue, De, R, N, K, CallPayoff) - analyticCallPrice) / epsilon;

    cout << "Call Delta: " << deltaCall << endl;
    cout << "Put Delta: " << deltaPut << endl;
    cout << "Vega: " << vega << endl;

    return 0;
}
