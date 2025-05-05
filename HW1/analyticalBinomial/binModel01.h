#pragma once


// computing risk-neutral probability (double U, double D, double R)
double riskNeutralProb(double U, double D, double R);

// computing the stock price at node (int n, int i)
double S(double S0, double U, double D, int n, int i);

// inputting, displaying and checking the model data
int getInputData(double* S0, double* U, double* D, double* R);