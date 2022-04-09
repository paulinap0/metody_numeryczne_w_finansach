#include <vector>
#include "BSModel.h"
#include "Options.h"

#include <cmath>

using namespace std;

double PathDepOption::PriceByMC(long N, BSModel model){
    SamplePath S;
    double sum = 0.0;
    double r = model.get_r();
    for(long i = 0; i < N; i++){
        S = model.generateSamplePath(m, T);
        sum = sum + Payoff(S);
    }
    return exp(-r * T) * sum / N;
}