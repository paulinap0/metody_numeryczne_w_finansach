#include <iostream>
#include <math.h>
#include <vector>
#include "BSModel.h"
#include "Options.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(){
    srand(3);
    cout << gauss() << endl;
    
    double S0 = 100, r = 0.03, sigma = 0.2;
    BSModel model (S0, r, sigma);
    int m = 30;
    double T = 1.0 / 12.0;
    SamplePath S = model.generateSamplePath(m, T);

    for(int i = 0; i < m; i++){
        cout << S[i] << endl;
    }
    return 0;
}
