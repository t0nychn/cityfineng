#pragma once

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));
double CallPayoff(double z, double K);
double PutPayoff(double z, double K);
double NewtonSymb(int N, int i);
double PriceAnalytic(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));