#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
// using namespace std;


float CDF(float mean, float stdev, float x){
    float erf_arg = (x - mean) / (pow(2, 0.5) * stdev);
    return (1 + erf(erf_arg))/2.;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    float a, n; 
    float mean, stdev;
    std::cin >> a >> n;
    std::cin >> mean >> stdev;

    printf ("%.4f\n", CDF(mean*n, stdev*pow(n, 0.5), a));
    return 0;
}
