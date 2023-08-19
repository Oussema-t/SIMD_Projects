#include <iostream>
#include <vector>

std::vector<double> fir_filter(const std::vector<double>& input, const std::vector<double>& coefficients) {
    std::vector<double> output(input.size());

    for (int n = 0; n < input.size(); n++) {
        double sum = 0;
        for (int k = 0; k < coefficients.size(); k++) {
            if (n >= k) {
                sum += input[n - k] * coefficients[k];
            }
        }
        output[n] = sum;
    }

    return output;
}

int main() {
    std::vector<double> input(100000);
    std::vector<double> coefficients(4); 
for (auto i = input.begin(); i != input.end(); ++i) {
    *i = std::distance(input.begin(), i) ;
    }    
// std::vector<double> coefficients = {0.1, 0.2, 0.3, 0.4};
for (auto j = coefficients.begin(); j != coefficients.end(); ++j) {
    *j = std::distance(coefficients.begin(), j) ;
    }   
std::vector<double> output = fir_filter(input, coefficients);

    for (const auto& e : output) {
        std::cout << e << " ";
    }
    return 0;
}
