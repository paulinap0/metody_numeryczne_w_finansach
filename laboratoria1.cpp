#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double S(int n, int i, double S0, double U, double D)
{
    return S0*pow(1+U,i)*pow(1+D,n-i);
}

void GetInputData(double &S0,double &U,double &D)
{
    cout<<"S0= "; cin>>S0;
    cout<<"U = "; cin>>U;
    cout<<"D = "; cin>>D;
}

double RiskNeutralProb(double U, double D, double R)
{
    return (R-D)/(U-D);
}

double CallPayoff(double S, double K)
{
    if(S<K) return 0;
    return S-K;
}

double PriceByCRR(double S0, double U,double D, double R,
                 int N, double K, double(*Payoff)(double S, double K))
{
    vector<double> H(N+1);
    double q = RiskNeutralProb(U,D,R);
    for(int i=0;i<N+1;i++) H[i]=Payoff(S(N,i,S0,U,D),K);

    for(int n=N-1;n>=0;n--)
    {
        for(int i=0;i<n+1;i++) H[i]=(q*H[i+1]+(1-q)*H[i])/(1+R);
    }
    return H[0];
}

int main()
{
    double S0=100, U=0.1, D=-0.1, R=0.05;
    int n=2, i=1, N=3;
    double K=105;
    //double (*f)(double x);
    //f = exp;
    //cout<<f(2)<<endl;
    //GetInputData(S0,U,D);

    cout << "S(u,i) = " << S(N,N,S0,U,D) << endl;
    cout << "Price  = " << PriceByCRR(S0,U,D,R,N,K,CallPayoff) << endl;
    return 0;
}
