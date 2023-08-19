#include <immintrin.h>
#include <Windows.h>
#include <chrono>
struct complex {
  float real;
  float imag;
};
complex operator+(const complex& a, const complex& b){
  __m128 a_vec = _mm_set_ps(a.imag, a.real, a.imag, a.real);
  __m128 b_vec = _mm_set_ps(b.imag, b.real, b.imag, b.real);
  __m128 c_vec = _mm_add_ps(a_vec, b_vec);
  complex c;
  c.real = c_vec[0];
  c.imag = c_vec[1];
  return c;
}
complex operator-(const complex& a, const complex& b) {
  __m128 a_vec = _mm_set_ps(a.imag, a.real, a.imag, a.real);
  __m128 b_vec = _mm_set_ps(b.imag, b.real, b.imag, b.real);
  __m128 c_vec = _mm_sub_ps(a_vec, b_vec);
  complex c;
  c.real = c_vec[0];
  c.imag = c_vec[1];
  return c;
}
complex operator*(const complex& a, const complex& b) {
  __m128 a_vec = _mm_set_ps(a.imag, a.real, a.imag, a.real);
  __m128 b_vec = _mm_set_ps(b.imag, b.real, b.imag, b.real);
  __m128 c_vec = _mm_mul_ps(a_vec, b_vec);
  complex c;
  c.real = c_vec[0];
  c.imag = c_vec[1];
  return c;
}
#include <iostream>
int main() {
  auto start = std::chrono::high_resolution_clock::now();
  complex a{3.0, 4.0};
  complex b{1.0, 2.0};
  complex z_1 = a + b;
  std::cout << "z_1 = " << z_1.real << " + " << z_1.imag << "i" << std::endl;
  complex z_2 = a - b;
  std::cout << "z_2 = " << z_2.real << " + " << z_2.imag << "i" << std::endl;
  complex z_3 = a * b;
  std::cout << "z_3 = " << z_3.real << " + " << z_3.imag << "i" << std::endl;
auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
  return 0;
}
