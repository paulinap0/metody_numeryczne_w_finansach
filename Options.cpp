#include <vector>
#include "BinModel.h"
#include "Options.h"

using namespace std;

double CallPayoff(double S, double K){
    if(S<K) return 0;
    return S-K;
}

double PutPayoff(double S, double K){
    if(S>K) return 0;
    return S-K;
}

double DigitalCall(double S, double K){
    if(S<K) return 0;
    return 1;
}

double DigitalPut(double S, double K){
    if(S>K) return 0;
    return 1;
}


Option::Option(int N_,double K_,double(*Payoff_)(double,double)){
    N=N_;
    K=K_;
    Payoff=Payoff_;
}
double Option::PriceByCRR(BinModel model){
    vector<double> H(N+1);
    double q = model.RiskNeutralProb();
    for(int i=0;i<N+1;i++) H[i]=Payoff(model.S(N,i),K);

    for(int n=N-1;n>=0;n--){
        for(int i=0;i<n+1;i++) H[i]=(q*H[i+1]+(1-q)*H[i])/(1 + model.get_R());
    }
    return H[0];
}