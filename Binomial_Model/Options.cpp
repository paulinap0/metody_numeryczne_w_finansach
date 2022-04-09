#include <vector>
#include "BinModel.h"
#include "Options.h"

using namespace std;

double Call::Payoff(double S){
    if(S<K) return 0;
    return S-K;
}

double Put::Payoff(double S){
    if(S>K) return 0;
    return K-S;
}

double Butterfly::Payoff(double S){
    if(S < K1) return 0.;
    if(S < 0.5 * (K1 + K2)) return S - K1;
    if(S < K2) return K2 - S;
    return 0.;
}

double Option::PriceByCRR(BinModel model){
    vector<double> H(N+1);
    double q = model.RiskNeutralProb();
    for(int i=0;i<N+1;i++) H[i]=Payoff(model.S(N,i));

    for(int n=N-1;n>=0;n--){
        for(int i=0;i<n+1;i++) H[i]=(q*H[i+1]+(1-q)*H[i])/(1 + model.get_R());
    }
    return H[0];
}