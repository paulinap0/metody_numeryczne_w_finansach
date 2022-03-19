#include <cmath>
#include <iostream>
#include "BinModel.h"
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


////////////////////////////////////////

void BinModel::display(){
    cout << "S0 = " << S0 << endl;
    cout << "U  = " << U << endl;
    cout << "D  = " << D << endl;
    cout << "R  = " << R << endl;
}

BinModel::BinModel(){
    S0=0; U=0; D=0; R=0;
}

BinModel::BinModel(double S0_,double U_,double D_,double R_){
    S0=S0_; U=U_; D=D_; R=R_;
}
