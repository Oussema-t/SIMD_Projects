#include <cstring>
#include <cmath>
#include <stdio.h>
#include <chrono>
#include<iostream>


// Define the number of rows and columns for the matrices
#define M 3
#define N 4
#define P 5

// Define the fixed-point type and number of fractional bits
typedef int32_t fix16_t;
const int FRACTIONAL_BITS = 16;

int main() {
 auto start = std::chrono::high_resolution_clock::now();
    std::cout<< "A: "<< std::endl; 

    // Declare the matrices as fixed-point variables
    fix16_t A[M][N], B[N][P], C[M][P];

    // Initialize the matrices with some values
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i+j;
         printf("%d ", A[i][j]);

        }
    printf("\n"); 

    }
    std::cout<< "B: "<< std::endl; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = i-j;
            printf("%d ", B[i][j]);

        }
     printf("\n"); 

    }

    // Perform the matrix multiplication
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            fix16_t sum = 0;
            for (int k = 0; k < N; k++) {
                sum += (A[i][k] * B[k][j]) >> FRACTIONAL_BITS;
            }
            C[i][j] = sum;
        }
    }
    std::cout<< "C: "<< std::endl; 

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
    return 0;
}
