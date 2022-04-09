#include <vector>
#include "BSModel.h"
#include "Options.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

const double pi = 4.0 * atan(1.0);

double uniformRandomVariable(){
    return (1.0 + rand()) / (1.0 + RAND_MAX); 
}

double gauss(){
    double U1 = uniformRandomVariable();
    double U2 = uniformRandomVariable();
    return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
}

BSModel::BSModel(double S0_, double r_, double sigma_){
    S0 = S0_;
    r = r_;
    sigma = sigma_;
}

SamplePath BSModel::generateSamplePath(int m, double T){
    double h = T/m;
    SamplePath S(m);
    // S(t1)
    S[0] = S0 * exp((r-0.5*pow(sigma,2)) * h + sigma * sqrt(h) * gauss());

    for(int i = 1; i < m; i++){
        S[i] = S[i-1] * exp((r - 0.5*pow(sigma,2)) * h + sigma * sqrt(h) * gauss());
    }
    return S;
}