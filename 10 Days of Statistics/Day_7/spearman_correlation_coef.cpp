#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
// using namespace std;


class Sample{
    public:
        Sample(const std::vector<float> &vals): sample(vals){
            M = updateMean();
            stdev = updateStDev();
        }

        float getMean() const{
            return M;
        }

        float getSigma() const{
            return stdev;
        }

        const std::vector<float> & getSample() const { 
            return sample; 
        }

    protected:
        const std::vector<float> &sample;
        float M;
        float stdev;

        float updateMean(){
            if (sample.size() == 0)
                throw std::runtime_error("No values");

            float sum = 0;
            for (unsigned i = 0; i < sample.size(); ++i)
                sum += sample.at(i);

            return sum/sample.size();
        }

        float updateStDev(){
            if (sample.size() == 0)
                throw std::runtime_error("No values");

            float numerator = 0;
            for (unsigned i = 0; i < sample.size(); ++i)
                numerator += pow(sample.at(i) - M, 2);

            return pow(numerator/sample.size(), 0.5);
        }
};


float PearsonCoef(const Sample& X, const Sample& Y){
    float meanX = X.getMean(), meanY = Y.getMean();
    float sigmaX = X.getSigma(), sigmaY = Y.getSigma();
    const std::vector<float> & X_vals = X.getSample();
    const std::vector<float> & Y_vals = Y.getSample();

    float numerator = 0;
    unsigned N = X_vals.size() < Y_vals.size()? X_vals.size() : Y_vals.size();
    for (unsigned i = 0; i < N; ++i)
        numerator += (X_vals.at(i) - meanX)*(Y_vals.at(i) - meanY);

    return numerator/(N * sigmaX * sigmaY);
}


void rankVec(const std::vector<float> & vals, std::vector<std::size_t>& vals_rank){
    std::map<float, std::size_t> locs;

    std::vector<float> vals_sorted = vals;
    std::sort(vals_sorted.begin(), vals_sorted.end());

    for (std::size_t i = 0; i < vals.size(); i++)
        locs.insert(std::make_pair(vals_sorted.at(i), i));

    for (std::size_t i = 0; i < vals.size(); i++)
        vals_rank.at(i) = locs.find(vals.at(i))->second + 1;
}


float SpearmanCoef(const Sample& X, const Sample& Y){
    const std::vector<float> & X_vals = X.getSample();
    const std::vector<float> & Y_vals = Y.getSample();

    std::vector<std::size_t> X_ranks(X_vals.size());
    rankVec(X_vals, X_ranks);
    std::vector<std::size_t> Y_ranks(Y_vals.size());
    rankVec(Y_vals, Y_ranks);

    return PearsonCoef(Sample(std::vector<float>(X_ranks.begin(), X_ranks.end())), 
                       Sample(std::vector<float>(Y_ranks.begin(), Y_ranks.end())));
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned n;
    std::cin >> n;
    std::vector<float> X(n);
    std::vector<float> Y(n);
    for (unsigned i = 0; i < n; ++i)
        std::cin >> X.at(i);
    for (unsigned i = 0; i < n; ++i)
        std::cin >> Y.at(i);

    printf("%.3f\n", SpearmanCoef(Sample(X), Sample(Y)));
    
    return 0;
}
