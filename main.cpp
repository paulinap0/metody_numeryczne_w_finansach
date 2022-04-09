#include <iostream>
#include <math.h>
#include <vector>
#include "BinModel.h"
#include "Options.h"
using namespace std;

//ćwiczenie
class KlasaGlowna{
private:
    double a;
public:
    KlasaGlowna(double a_){a=a_;}
    KlasaGlowna(){}
    double f(double x){return a*x*x;}
};

class podklasa: public KlasaGlowna{
private:
    double b;
public:
    podklasa(double a_, double b_) :KlasaGlowna(a_) {b=b_;}
    double g(double x){return 2*x;}
};

class Integral{
private:
    int n;
    double a, b;
    double(*f)(double x);
public:
    Integral(int n_, double a_, double b_, double(*f_)(double x)){
        n_ = n, a_ = a, b_ = b, f_ = f;
    }
    double field(){
        double s = 0;
        double dx = (b - a)*1.0 / n;
        for(int i=1; i<=n; i++){ 
            s += f(a + i * dx);
            cin >> s;
        }
        s *= dx;
        return s;
    }
};

    double f(double x){return x;}

int main(){
    int n = 100;
    double a = 0., b = 5.;
    Integral Calka(n, a, b, f);
    cout << "Integral = " << Calka.field() << endl;

    //KlasaGlowna objA(3);
    //cout << objA.f(5) << endl;

    //podklasa x(3,2);
    //cout << x.f(5) << endl;
    //cout << x.g(5) << endl;
    //return 0;

    double S0=120, U=0.1, D=-0.1, R=0.05, K=105;
    int N=3;
    double K1=100, K2=120;

    Call MojeCall(N,K);
    Put MojePut(N,K);
    Butterfly MojeButterfly(N,K1,K2);

    BinModel model(S0,U,D,R);

    cout << "Price  = " << MojeCall.PriceByCRR(model) << endl;
    cout << "Price  = " << MojePut.PriceByCRR(model) << endl;
    cout << "Price  = " << MojeButterfly.PriceByCRR(model) << endl;
    return 0;
}
