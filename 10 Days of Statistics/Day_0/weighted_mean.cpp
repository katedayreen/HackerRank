#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
//using namespace std;


double weightedMean(const std::vector<int>& values, const std::vector<int>& weights){
    double sum = 0.;
    double weights_sum = 0.;
    double curr_weight;
    for (unsigned i = 0; i < values.size(); ++i){
        curr_weight = static_cast<double>(weights.at(i));
        sum += curr_weight*static_cast<double>(values.at(i));
        weights_sum += curr_weight;
    }
    return sum / weights_sum;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned size;
    std::cin >> size;
    std::vector<int> values(size);
    for (unsigned i = 0; i < size; i++) 
        std::cin >> values.at(i);
    
    std::vector<int> weights(size);
    for (unsigned i = 0; i < size; i++) 
        std::cin >> weights.at(i);

    printf("%.1f\n", weightedMean(values, weights));
    return 0;
}
