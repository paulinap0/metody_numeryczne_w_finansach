#ifndef BinModel_h
#define BinModel_h
#include <cmath>

class BinModel{
private:
    double S0, U, D, R;
public:
    void display();
    void GetInputData();
    double RiskNeutralProb(){return (R-D)/(U-D);}
    double S(int n, int i){return S0 * pow(1.0+U,i)*pow(1.0+D,n-i);}
    double get_R(){return R;}

    BinModel();
    BinModel(double S0_,double U_,double D_,double R_);
};


#endif // BinModel_h

