#ifndef Options_h
#define Options_h
#include "BSModel.h"

class PathDepOption{
private:
    double T;
    int m;
public:
    virtual double Payoff(const SamplePath &S)=0;
    double PriceByMC(long N, BSModel model);
};


#endif // Options_h