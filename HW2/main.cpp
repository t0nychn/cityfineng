#include <iostream>
#include "binModel.h"
#include "options.h"
using namespace std;

int main()
{
    BinModel Model;

    if (Model.GetInputData() == 1)
        return 1;

    Call Option1;
    Option1.GetInputData();

    cout << "European call option price = " << Option1.PriceByCRR(Model) << endl;

    Put Option2;
    Option2.GetInputData();

    cout << "European put option price = " << Option2.PriceByCRR(Model) << endl;

    DoubleDigital doubleDigitalOption;
    doubleDigitalOption.GetInputData();

    cout << "Double digital Price = " << doubleDigitalOption.PriceByCRR(Model) << endl;

    return 0;
}