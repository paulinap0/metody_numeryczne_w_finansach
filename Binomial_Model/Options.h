#ifndef Options_h
#define Options_h
#include "BinModel.h"

class Option{
private:
    int N;
public:
    //virtual double Payoff(double S){return 0.0;}
    virtual double Payoff(double S)=0;
    double PriceByCRR(BinModel model);
    Option(int N_) {N=N_;};
};

class Call: public Option{
private:
    double K;
public:
    Call(int N, double K_): Option(N) {K=K_;}
    double Payoff(double S);
};

class Put: public Option{
private:
    double K;
public:
    Put(int N, double K_): Option(N) {K=K_;}
    double Payoff(double S);
};

class Butterfly: public Option{
private:
    double K1, K2;
public:
    Butterfly(int N, double K1_, double K2_): Option(N) {K1=K1_, K2=K2_;}
    double Payoff(double S);
};

#endif // Options_h