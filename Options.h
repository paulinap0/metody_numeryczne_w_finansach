#ifndef Options_h
#define Options_h

double CallPayoff(double S, double K);

double PriceByCRR(double S0, double U,double D, double R,
                 int N, double K, double(*Payoff)(double S, double K));

#endif // Options_h