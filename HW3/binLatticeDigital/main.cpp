#include "binLattice.h"
#include "binModel.h"
#include "options.h"
#include <iostream>
using namespace std;

int main() {
    BinModel Model;
    if (Model.GetInputData() == 1)
        return 1;

    Call Call_Option;
    Call_Option.GetInputData();

    Put Put_Option;
    Put_Option.GetInputData();

    BinLattice<double> callOptionPriceTree;
    BinLattice<bool> callOptionStoppingTree;
    BinLattice<double> callOptionDeltaTree;
    BinLattice<double> callOptionCashTree;

    BinLattice<double> putOptionPriceTree;
    BinLattice<bool> putOptionStoppingTree;
    BinLattice<double> putOptionDeltaTree;
    BinLattice<double> putOptionCashTree;

    double americanCallOptionPrice = Call_Option.PriceBySnell(Model, callOptionPriceTree, callOptionStoppingTree);
    double americanPutOptionPrice = Put_Option.PriceBySnell(Model, putOptionPriceTree, putOptionStoppingTree);



    double europeanCallOptionPrice = Call_Option.PriceByCRR(Model, callOptionDeltaTree, callOptionCashTree);
    double europeanPutOptionPrice = Put_Option.PriceByCRR(Model, putOptionDeltaTree, putOptionCashTree);

    cout << "American Call prices: " << endl << endl;
    callOptionPriceTree.Display();

    cout << "American Call exercise policy: " << endl << endl;
    callOptionStoppingTree.Display();

    cout << "American Call Option price: " << americanCallOptionPrice << endl;


    cout << "American Put prices: " << endl << endl;
    putOptionPriceTree.Display();

    cout << "American Put exercise policy: " << endl << endl;
    putOptionStoppingTree.Display();

    cout << "American Put Option price: " << americanPutOptionPrice << endl;


    cout << "European Call Option Delta Tree: " << endl << endl;
    callOptionDeltaTree.Display();

    cout << "European Call Option Cash Tree: " << endl << endl;
    callOptionCashTree.Display();

    cout << "European Call price: " << europeanCallOptionPrice << endl;



    cout << "European Put Option Delta Tree: " << endl << endl;
    putOptionDeltaTree.Display();

    cout << "European Put Option Cash Tree: " << endl << endl;
    putOptionCashTree.Display();

    cout << "European Put price: " << europeanPutOptionPrice << endl;

    return 0;
}