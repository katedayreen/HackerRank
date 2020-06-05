#include <cmath>
#include <cstdio>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;


float factorial(const int x){
    if (x == 0)
        return 1;
    float factor = 1;
    for (int i = 1; i <= x; ++i)
        factor *= i;
    return factor;
}


class Binomial{
    public: 
        Binomial(unsigned n, double p){
            if (p > 1 || p < 0)
                std::__throw_runtime_error("P must be in [0, 1]");
            this->p = p;
            this->n = n;
        }
        unsigned n;
        double p;

        float FmoreThan(unsigned min_val){
            if (min_val > n)
                return 0;

            float F = 0., C_n_k = 0.;
            for (unsigned k = min_val; k <= n; ++k){
                C_n_k = factorial(n)/(factorial(k)*factorial(n - k));
                F += C_n_k*std::pow(p, k)*std::pow(1 - p, n - k);
            }
            return F;
        }

        float FlessThan(unsigned max_val){
            if (max_val > n)
                return 0;

            float F = 0., C_n_k = 0.;
            for (unsigned k = 0; k <= max_val; ++k){
                C_n_k = factorial(n)/(factorial(k)*factorial(n - k));
                F += C_n_k*std::pow(p, k)*std::pow(1 - p, n - k);
            }
            return F;
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    float p;
    unsigned n;
    std::cin >> p;
    std::cin >> n;
    p /= 100.;

    Binomial distr = Binomial(n, p);
    std::cout << round(distr.FlessThan(2)*1000)/1000 << '\n';
    std::cout << round(distr.FmoreThan(2)*1000)/1000 << '\n';
    return 0;
}

