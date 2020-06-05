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
    float mean, stdev;
    float a0;
    float a, b; 
    std::cin >> mean >> stdev;
    std::cin >> a0;
    std::cin >> a >> b;
    printf ("%.3f\n", CDF(mean, stdev, a0));
    printf ("%.3f\n", CDF(mean, stdev, b) - CDF(mean, stdev, a));
    return 0;
}
