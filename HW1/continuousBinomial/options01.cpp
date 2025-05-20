#include "options01.h"
#include "binModel01.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double CallPayoff(double z, double K) {
    return max(z - K, 0.0);
}

double PutPayoff(double z, double K) {
    return max(K - z, 0.0);
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K)) {
    double q = riskNeutralProb(U, D, R);
    double Price[N + 1];

    for (int i = 0; i <= N; i++) {
        Price[i] = Payoff(S(S0, U, D, N, i), K);
    }

    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R); // changed to continuous time R
        }
    }

    return Price[0];
}

double PriceAnalytic(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K)) {
    double q = riskNeutralProb(U, D, R);
    vector<double> PDF(N + 1);
    double PDFSum = 0.0;

    for (int i = 0; i <= N; i++) {
        PDF[i] = NewtonSymb(N, i) * pow(q, i) * pow(1 - q, N - i);
        PDFSum += PDF[i];
    }

    double result = 0.0;
    for (int i = 0; i <= N; i++) {
        double price = Payoff(S(S0, U, D, N, i), K);
        result += PDF[i] * price;
    }

    result /= pow(1 + R, N);
    return result;
}

double NewtonSymb(int N, int i) {
    if (i < 0 || i > N)
        return 0.0;

    double result = 1.0;
    for (int k = 1; k <= i; k++) {
        result *= (N - i + k) / static_cast<double>(k);
    }
    return result;
}