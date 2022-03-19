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
    //double (*f)(double x);
    //f = exp;
    //cout<<f(2)<<endl;
    //GetInputData(S0,U,D);

    cout << "S(u,i) = " << S(N,N,S0,U,D) << endl;
    cout << "Price  = " << PriceByCRR(S0,U,D,R,N,K,CallPayoff) << endl;
    return 0;
}