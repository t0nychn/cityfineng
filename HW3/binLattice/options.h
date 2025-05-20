#pragma once

#include "binLattice.h"
#include "binModel.h"

class Option {
private:
    int N; // steps to expiry

public:
    void SetN(int N_) {N=N_;}
    int GetN() {return N;}
    virtual double Payoff(double z) = 0;
};

class EurOption : public virtual Option {
public:

    double PriceByCRR(BinModel Model, BinLattice<double> &DeltaTree, BinLattice<double> &CashPositionTree);
    double PriceAnalytic();
};

class AmOption : public virtual Option {
public:
    // pricing American option
    double PriceBySnell(BinModel Model,
                        BinLattice<double>& PriceTree,
                        BinLattice<bool>& StoppingTree);
};

class Call : public EurOption, public AmOption {
private:
    double K; // strike price
public:
    void SetK(double K_) {
        K=K_;
    }
    int GetInputData();
    double Payoff(double z);
};

class Put : public EurOption, public AmOption {
private:
    double K; // strike price

public:
    void SetK(double K_) {K=K_;}
    int GetInputData();
    double Payoff(double z);
};
