#include <cmath>
#include <cstdio>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
//using namespace std;


float median(const std::vector<int>::iterator &start, 
                const std::vector<int>::iterator &end){
    std::sort(start, end);

    int len = std::distance(start, end);
    unsigned middle = len/2;
    std::vector<int>::iterator it = start + middle;

    if (len % 2 == 0)
        return static_cast<float>((*std::prev(it, 1) + *it)/2.);
    else return static_cast<float>(*it);
}


void quartiles(std::vector<int>& values, std::vector<float>& quartiles_output){
    int Q1, Q2, Q3;
    // sorts values
    Q2 = static_cast<int>(median(values.begin(), values.end()));
    
    unsigned len = values.size();
    unsigned middle = len/2;
    std::vector<int>::iterator middle_it = values.begin() + middle;

    Q1 = median(values.begin(), middle_it);
    if (len % 2 == 0){
        Q3 = median(middle_it, values.end());
    }
    else {
        Q3 = median(std::next(middle_it, 1), values.end());
    }

    quartiles_output.push_back(Q1);
    quartiles_output.push_back(Q2);
    quartiles_output.push_back(Q3);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned size;
    std::cin >> size;
    std::vector<int> values_unique(size);
    for (unsigned i = 0; i < size; ++i) 
        std::cin >> values_unique.at(i);
    
    std::vector<int> counts(size);
    for (unsigned i = 0; i < size; ++i) 
        std::cin >> counts.at(i);
    
    std::vector<int> values;
    for (unsigned i = 0; i < size; ++i) 
        for(unsigned j = 0; j < counts.at(i); ++j){
            values.push_back(values_unique.at(i));
        }

    std::vector<float> quartiles_output;
    quartiles(values, quartiles_output);

    printf("%.1f\n", quartiles_output.at(2) - quartiles_output.at(0));
    return 0;
}
