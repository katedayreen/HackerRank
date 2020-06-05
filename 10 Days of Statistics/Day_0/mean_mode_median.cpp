#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
//using namespace std;


double mean(const std::vector<int>& values){
    double sum = 0;
    for (unsigned i = 0; i < values.size(); ++i)
        sum += static_cast<double>(values.at(i));

    return sum / values.size();
}


void bubbleSort(std::vector<int>& values){
    bool done = false;
    int smaller;
    while (done != true){
        done = true;
        for (unsigned i = 1; i < values.size(); ++i){
            if (values.at(i - 1) > values.at(i)){
                smaller = values.at(i);
                values.at(i) = values.at(i - 1);
                values.at(i - 1) = smaller;
                done = false;
            }
        }
    } 
}


float median(std::vector<int>& values){
    bubbleSort(values);
    unsigned len = values.size();

    if (len == 1)
        return static_cast<float>(values.at(0));

    unsigned middle = len/2;
    if (len % 2 == 0){
        return static_cast<float>((values.at(middle - 1) + values.at(middle))/2.);
    }
    else return static_cast<float>(values.at(middle));
}


int mode(std::vector<int>& values){
    bubbleSort(values);
    int cur_el = values.at(0);
    int mode = values.at(0);
    unsigned cur_count = 1; 
    unsigned max_count = 1;
    for (unsigned i = 1; i < values.size(); ++i)
        if (values.at(i) == cur_el)
            ++cur_count;
        else if(cur_count > max_count){
            mode = values.at(i - 1);
            max_count = cur_count;

            cur_el = values.at(i);
            cur_count = 1;
        }
        else {
            cur_el = values.at(i);
            cur_count = 1;
        }
    if(cur_count > max_count)
        mode = values.back();

    return mode;
}


int main() {
    unsigned size;
    std::cin >> size;
    std::vector<int> values(size);
    for (unsigned i = 0; i < size; i++) 
        std::cin >> values.at(i);
    
    printf("%.1f\n", mean(values));
    printf("%.1f\n", median(values));
    std::cout << mode(values) << '\n';
    return 0;
}

