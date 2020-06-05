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
    float good, minimum; 
    std::cin >> mean >> stdev;
    std::cin >> good >> minimum;

    printf ("%.2f\n", (1 - CDF(mean, stdev, good))*100);
    printf ("%.2f\n", (1 - CDF(mean, stdev, minimum))*100);
    printf ("%.2f\n", CDF(mean, stdev, minimum)*100);
    return 0;
}
