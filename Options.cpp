#include <vector>
#include "BinModel.h"

using namespace std;

double CallPayoff(double S, double K){
    if(S<K) return 0;
    return S-K;
}

double PriceByCRR(double S0, double U,double D, double R,
                 int N, double K, double(*Payoff)(double S, double K)){
    vector<double> H(N+1);
    double q = RiskNeutralProb(U,D,R);
    for(int i=0;i<N+1;i++) H[i]=Payoff(S(N,i,S0,U,D),K);

    for(int n=N-1;n>=0;n--)
    {
        for(int i=0;i<n+1;i++) H[i]=(q*H[i+1]+(1-q)*H[i])/(1+R);
    }
    return H[0];
}