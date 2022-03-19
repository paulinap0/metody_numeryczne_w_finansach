#ifndef BinModel_h
#define BinModel_h

double S(int n, int i, double S0, double U, double D);

void GetInputData(double &S0,double &U,double &D);

double RiskNeutralProb(double U, double D, double R);

////////////////////////////////////////////////

class BinModel
{
private:
    double S0, U, D, R;
public:
    void display();
    void GetInputData();
    double RiskNeutralProb(){return (R-D)/(U-D);}

    BinModel();
    BinModel(double S0_,double U_,double D_,double R_);
};


#endif // BinModel_h

