#include "options.h"
#include "binModel.h"
#include <iostream>
using namespace std;

double EurOption::PriceByCRR(BinModel Model)
{
    double q = Model.RiskNeutralProb();
    double Price[N + 1];

    for (int i = 0; i <= N; i++)
    {
        Price[i] = Payoff(Model.S(N, i));
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.GetR());
        }
    }
    return Price[0];
}

int Call::GetInputData()
{
    cout << "Enter call option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: ";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K: ";
    cin >> K;
    cout << endl;
    return 0;
}

double Call::Payoff(double z)
{
    if (z > K)
        return z - K;
    return 0.0;
}

int Put::GetInputData()
{
    cout << "Enter put option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: ";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K: ";
    cin >> K;
    cout << endl;
    return 0;
}

double Put::Payoff(double z)
{
    if (z < K)
        return K - z;
    return 0.0;
}

int DoubleDigital::GetInputData()
{
    cout << "Enter double digital option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: ";
    cin >> N;
    SetN(N);
    cout << "Enter lower strike price K1: ";
    cin >> K1;
    cout << "Enter upper strike price K2: ";
    cin >> K2;
    cout << endl;
    return 0;
}

double DoubleDigital::Payoff(double z)
{
    if (z > K1 && z < K2)
        return 1.0;
    return 0.0;
}