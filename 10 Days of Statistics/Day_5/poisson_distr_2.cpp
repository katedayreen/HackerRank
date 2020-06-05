#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    float L1, L2;
    std::cin >> L1 >> L2;

    float E_cost1 = 160 + 40*(L1 + pow(L1, 2));
    float E_cost2 = 128 + 40*(L2 + pow(L2, 2));

    std::cout << round(E_cost1 * 1000) / 1000. << '\n';
    std::cout << round(E_cost2 * 1000) / 1000. << '\n';

    return 0;
}
