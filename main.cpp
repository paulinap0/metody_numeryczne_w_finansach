#include <iostream>
#include <math.h>
#include <vector>
#include "BinModel.h"
#include "Options.h"
using namespace std;

int main(){
    double S0=120, U=0.1, D=-0.1, R=0.05, K=105;
    int N=3;

    Option call(N,K,CallPayoff);
    Option put(N,K,PutPayoff);

    BinModel model(S0,U,D,R);

    cout << "Price  = " << call.PriceByCRR(model) << endl;
    cout << "Price  = " << put.PriceByCRR(model) << endl;

    return 0;
}
