#include <iostream>
#include <math.h>
#include <vector>
#include "BinModel.h"
#include "Options.h"
using namespace std;

int main(){
    double S0=100, U=0.1, D=-0.1, R=0.05;
    int n=2, i=1, N=3;
    double K=105;


    cout << "S(n,i) = " << S(n,i,S0,U,D) << endl;
    cout << "Price  = " << PriceByCRR(S0,U,D,R,N,K,CallPayoff) << endl;

    BinModel model(S0,U,D,R);

    //model.D=-0.1;
    //model.U=0.1;
    //model.R=0.05;
    //model.S0=123;

    model.display();

    return 0;
}
