#ifndef BSModel_h
#define BSModel_h
#include <cmath>

#include <vector>
using namespace std;

typedef vector<double> SamplePath;

double gauss();

class BSModel{
private:
    double S0, r, sigma;
public:
    BSModel(double S0, double r, double sigma);
    SamplePath generateSamplePath(int m, double T);
    double get_r(){return r;}
};

#endif // BSModel_h
