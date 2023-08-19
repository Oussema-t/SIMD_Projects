ude <iostream>
#include <vector>
#include <xmmintrin.h>


std::vector<double> low_pass_filter(const std::vector<double>& input, double cutoff_frequency, double sample_rate) {
            // std::cout<< "HALLO"<< std::endl; 

    // Create a vector to store the output
    std::vector<double> output(input.size());

    // Calculate the filter coefficient
    double alpha = cutoff_frequency / sample_rate;
std::cout<<alpha  << std::endl;

    // Initialize the previous output sample
    double previous_output = input[0];


        // // Load the previous output sample into another SIMD register
        // __m128d y = _mm_set1_pd(previous_output);
        // double y_1 = _mm_cvtsd_f64(y);
        // std::cout<<"y:" <<  y_1 << std::endl; 
        // // Load the filter coefficient into another SIMD register
        // __m128d a = _mm_set1_pd(alpha);



    // Apply the filter to each sample of the input
    for (int i = 0; i < input.size(); i += 4) {
        // Load four input samples into a SIMD register
        __m128d x = _mm_loadu_pd(&input[i]);

        // Load the previous output sample into another SIMD register
        __m128d y = _mm_set1_pd(previous_output);
  double y_1 = _mm_cvtsd_f64(y);
        std::cout<<"y:" <<  y_1 << std::endl; 
        std::cout<<" "<< std::endl; 

        // Load the filter coefficient into another SIMD register
        __m128d a = _mm_set1_pd(alpha);
 double a_1 = _mm_cvtsd_f64(y);
        std::cout<<"a:" <<  a_1 << std::endl; 
        std::cout<<" "<< std::endl; 

        // Calculate the filtered output using SIMD instructions
        __m128d y_new = _mm_add_pd(_mm_mul_pd(a, x), _mm_mul_pd(_mm_sub_pd(_mm_set1_pd(1.0), a), y));
 double y_new_1 = _mm_cvtsd_f64(y_new);
        std::cout<<"y_new:" <<  y_new_1 << std::endl; 
        std::cout<<" "<< std::endl; 
        // Store the filtered output in the output vector
        _mm_storeu_pd(&output[i], y_new);

        // Update the previous output sample
        previous_output = _mm_cvtsd_f64(y_new);
        std::cout<<" "<< std::endl; 
        std::cout<< "previous_output: "<<previous_output << std::endl; 

          std::cout<<" "<< std::endl; 
    }

    return output;
}

int main() {
    // Create an input signal
    // std::vector<double> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    
    std::vector<double> input(20);
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

    return 0; 
    
     } 
