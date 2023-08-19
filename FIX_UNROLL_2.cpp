#include <iostream>
using namespace std;

// Define the number of rows and columns for the matrices
const int M = 3;
const int N = 4;
const int P = 5;

int main() {
    // Declare the matrices as floating-point variables
    int A[M][N], B[N][P], C[M][P];
    cout<< "A: "<< endl; 
    // Initialize the matrices with some values
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i+j) ;
             printf("%d ", A[i][j]);

        }
     printf("\n"); 
           
    }
    cout<< "B: "<< endl; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = (double)(i-j);
            printf("%d ", B[i][j]);
        }
        printf("\n"); 

    }

    // Perform the matrix multiplication
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout<< "C: "<< endl; 
    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


