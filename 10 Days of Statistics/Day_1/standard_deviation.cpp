#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;


float STD(const std::vector<int> &values){
    float mean = 0.;
    for(std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it)
        mean += *it;
    mean /= values.size();

    float var = 0.;
    for(auto it = values.begin(); it != values.end(); ++it)
        var += pow(*it - mean, 2);
    var /= values.size();
    
    return pow(var, 0.5);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned size;
    std::cin >> size;  
    std::vector<int>values(size);
    for(unsigned i = 0; i < size; ++i)
        std::cin >> values.at(i);

    printf("%.1f\n", STD(values));
    return 0;
}
