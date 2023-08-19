#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <chrono>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow);
 
struct complex {
    float real;
    float imag;
};

const int N = 4;

void matrix_mult(complex* a, complex* b, complex* c) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            __m128 a_vec = _mm_set_ps(a[i * N + j].imag, a[i * N + j].real, a[i * N + j].imag, a[i * N + j].real);
            __m128 b_vec = _mm_set_ps(b[j * N + i].real, b[j * N + i].imag, b[j * N + i].real, b[j * N + i].imag);
            __m128 c_vec = _mm_mul_ps(a_vec, b_vec);
            c[i * N + j].real = c_vec[0] - c_vec[1];
            c[i * N + j].imag = c_vec[0] + c_vec[1];
        }
    }
}



int main() {
    complex a[N][N] = {{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}}};
    complex b[N][N] = {{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
                      {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}}};
    complex c[N][N];


     // Start the timer
 auto start = std::chrono::high_resolution_clock::now();

    // Perform matrix multiplication
    matrix_mult(*a, *b, *c);

    

   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << c[i][j].real << " + " << c[i][j].imag << "i" << "  ";
        }
        std::cout << std::endl;
    }
    // Stop the timer
   auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;

    return 0;
}

