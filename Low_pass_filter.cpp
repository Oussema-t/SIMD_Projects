#include <iostream>
#include <vector>
#include <chrono>
// #include <xlnt/xlnt.hpp>
#include <fstream>


std::vector<double> low_pass_filter(const std::vector<double>& input, double cutoff_frequency, double sample_rate) {
    // Create a vector to store the output
    std::vector<double> output(input.size());
    // Calculate the filter coefficient
    double alpha = cutoff_frequency / sample_rate;
// std::cout<< alpha  << std::endl;

    // Initialize the previous output sample
    double previous_output = input[0];

    // Apply the filter to each sample of the input
    for (int i = 0; i < input.size(); i++) {
        // Apply the filter equation
        output[i] = alpha * input[i] + (1 - alpha) * previous_output;

        // Update the previous output sample
        previous_output = output[i];
    }

    return output;
}

int main() {

auto start = std::chrono::high_resolution_clock::now();
// Create an input signal
std::vector<double> input(100);
    // std::vector<double> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (auto i = input.begin(); i != input.end(); ++i) {
    *i = std::distance(input.begin(), i) ;
    }    
    // Set the cutoff frequency and sample rate
    double cutoff_frequency = 2.0;
    double sample_rate = 10.0;
    // Apply the low-pass filter
    std::vector<double> output = low_pass_filter(input, cutoff_frequency, sample_rate);
    // Print the filtered output
    for (const auto& e : output) {
        std::cout << e << " ";
    }
    std::ofstream outfile;
outfile.open("output.csv");
for(auto const& value: output) {
    outfile << value << ",";
}
outfile.close();

std::cout<<" "<< std::endl; 
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
    return 0;
}
