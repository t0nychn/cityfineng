#pragma once
#include "binModel.h"

class EurOption
{
private:
    int N; // steps to expiry

public:
    void SetN(int N_) { N=N_;}
    virtual double Payoff(double z) = 0;
    double PriceByCRR(BinModel Model);
};

class Call : public EurOption
{
private:
    double K; // strike price
public:
    void SetK(double K_) { K=K_; }
    int GetInputData();
    double Payoff(double z);
};

class Put : public EurOption
{
private:
    double K; // strike price

public:
    void SetK(double K_) { K=K_; }
    int GetInputData();
    double Payoff(double z);
};



class DoubleDigital : public EurOption{
private:
    double K1; // lower strike price
    double K2; // upper strike price

public:
    void SetK(double K1, double K2) { this->K1 = K1; this->K2 = K2; }
    int GetInputData();
    double Payoff(double z);
};