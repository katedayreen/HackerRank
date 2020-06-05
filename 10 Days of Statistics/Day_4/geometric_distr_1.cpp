#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numerator, denominator;
    int x;
    std::cin >> numerator;
    std::cin >> denominator;
    std::cin >> x;

    float p = (float)numerator/denominator;
    float P = p*pow(1 - p, x - 1);
    std::cout << round(P*1000)/1000 << '\n';
    return 0;
}
