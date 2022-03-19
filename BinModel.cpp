#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

double S(int n, int i, double S0, double U, double D){
    return S0*pow(1+U,i)*pow(1+D,n-i);
}

void GetInputData(double &S0,double &U,double &D){
    cout<<"S0= "; cin>>S0;
    cout<<"U = "; cin>>U;
    cout<<"D = "; cin>>D;
}

double RiskNeutralProb(double U, double D, double R){
    return (R-D)/(U-D);
}