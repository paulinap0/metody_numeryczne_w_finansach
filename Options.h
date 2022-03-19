#ifndef Options_h
#define Options_h
#include "BinModel.h"

double CallPayoff(double S, double K);
double PutPayoff(double S, double K);
double DigitalCall(double S, double K);
double DigitalPut(double S, double K);

class Option{
private:
    double K;
    int N;
    double(*Payoff)(double S, double K);
public:
    double PriceByCRR(BinModel model);

    Option(int N_, double K_, double(*Payoff_)(double, double));

};

class Call: public Option{

};

#endif // Options_h