#pragma once

class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;

public:
    double RiskNeutralProb();
    double S(int n, int i);
    int GetInputData();
    double GetR();
};