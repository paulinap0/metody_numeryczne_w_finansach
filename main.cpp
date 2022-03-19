#include <iostream>
#include <math.h>
#include <vector>
#include "BinModel.h"
#include "Options.h"
using namespace std;

int main(){
    double S0=120, U=0.1, D=-0.1, R=0.05;
    int n=2, i=1, N=3;
    double K=105;

    BinModel model(S0,U,D,R);

    model.display();

    return 0;
}
