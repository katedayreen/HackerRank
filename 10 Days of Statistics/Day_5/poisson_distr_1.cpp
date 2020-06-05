#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
// using namespace std;


float factorial(float x){
    if (x < 0)
        throw std::runtime_error("Factorial of negative numbers is not defined");
    if (x == 0)
        return 1;
    else
        return x*factorial(x - 1);
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    float L, x;
    std::cin >> L;
    std::cin >> x;

    float P = pow(L, x) * std::exp(-L) / factorial(x);
    std::cout << round(P * 1000)/1000 << '\n';
    return 0;
}
