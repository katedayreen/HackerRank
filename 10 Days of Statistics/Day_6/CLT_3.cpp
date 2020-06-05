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
    float n; 
    float mean, stdev;
    float percentage, z_score;
    std::cin >> n;
    std::cin >> mean >> stdev;
    std::cin >> percentage >> z_score;

    float A = mean - z_score*stdev / pow(n, 0.5);
    float B = mean + z_score*stdev / pow(n, 0.5);
    printf ("%.2f\n", A);
    printf ("%.2f\n", B);
    return 0;
}
