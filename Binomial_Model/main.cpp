#include <iostream>
#include <math.h>
#include <vector>
#include "BinModel.h"
#include "Options.h"
using namespace std;


int main(){
    double S0=120, U=0.1, D=-0.1, R=0.05, K=105;
    int N=3;
    double K1=100, K2=120;

    Call MojeCall(N,K);
    Put MojePut(N,K);
    Butterfly MojeButterfly(N,K1,K2);

    BinModel model(S0,U,D,R);

    cout << "Price  = " << MojeCall.PriceByCRR(model) << endl;
    cout << "Price  = " << MojePut.PriceByCRR(model) << endl;
    cout << "Price  = " << MojeButterfly.PriceByCRR(model) << endl;
    return 0;
}
