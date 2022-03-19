#ifndef Options_h
#define Options_h

double CallPayoff(double S, double K);

double PriceByCRR(BinModel model, int N, double K, double(*Payoff)(double S, double K));

#endif // Options_h