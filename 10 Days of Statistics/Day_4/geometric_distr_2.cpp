#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numerator, denominator;
    unsigned x;
    std::cin >> numerator;
    std::cin >> denominator;
    std::cin >> x;

    float p = (float)numerator/denominator;
    float P = 0.;
    for(unsigned i = 1; i <= x; ++i)
        P += p*pow(1 - p, i - 1);
    std::cout << round(P*1000)/1000 << '\n';
    return 0;
}
