#include "binModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

double riskNeutralProb(double U, double D, double R) {
    double q = (R - D) / (U - D);
    return q;
}

double S(double S0, double U, double D, int n, int i) {
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

int getInputData(double *S0, double *U, double *D, double *R)
{
    // Entering data
    cout << "Enter S0: ";
    cin >> *S0; // 100
    cout << "Enter U: ";
    cin >> *U;  // 0.9
    cout << "Enter D: ";
    cin >> *D;  // -0.3
    cout << "Enter R: ";
    cin >> *R;  // 0.1

    // Make sure S0 > 0, (1 + U) > 0, (1 + D) > 0, (1 + R) > 0, U < D, otherwise interchange U <-> D
    if (*S0 <= 0 || *U <= -1.0 || *D <= -1.0 || *R <= -1.0 || *U <= *D)
    {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    // Checking for arbitrage D < R < U; q > 1 or q < 0; q = (R - D) / (U - D)
    if (*R <= *D || *R >= *U) // dereference or you're just comparing addresses
    {
        cout << "Arbitrage exists" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    cout << "Input data checked" << endl;
    cout << "There is no Arbitrage" << endl;
    return 0;
}
