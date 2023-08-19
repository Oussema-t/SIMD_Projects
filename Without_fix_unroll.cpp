#include <iostream>
#include <chrono>

using namespace std;

// Define the number of rows and columns for the matrices
const int M = 3;
const int N = 4;
const int P = 5;

int main() {
 auto start = std::chrono::high_resolution_clock::now();

    // Declare the matrices as floating-point variables
    int A[M][N], B[N][P], C[M][P];
    std::cout<< "A: "<< std::endl; 
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
int rows = sizeof(B)/sizeof(B[0]);
    int cols = sizeof(B[0])/sizeof(B[0][0]);
    cout<<"rows: "<<rows<<","<<"cols: "<<cols<<endl;
    // Perform the matrix multiplication
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] = A[i][k] * B[k][j];
            }
        }
    }
    std::cout<< "C: "<< std::endl; 

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
    return 0;
}

