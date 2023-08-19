
#include <chrono>

struct complex {
  float real;
  float imag;
};

complex operator+(const complex& a, const complex& b) {
  complex c;
  c.real = a.real + b.real;
  c.imag = a.imag + b.imag;
  return c;
}

complex operator-(const complex& a, const complex& b) {
  complex c;
  c.real = a.real - b.real;
  c.imag = a.imag - b.imag;
  return c;
}

complex operator*(const complex& a, const complex& b) {
  complex c;
  c.real = a.real * b.real - a.imag * b.imag;
  c.imag = a.real * b.imag + a.imag * b.real;
  return c;
}


#include <iostream>

int main() {
auto start = std::chrono::high_resolution_clock::now();

  complex a{3.0, 4.0};
  complex b{1.0, 2.0};

  complex c = a + b;
  std::cout << "c = " << c.real << " + " << c.imag << "i" << std::endl;

  complex d = a - b;
  std::cout << "d = " << d.real << " + " << d.imag << "i" << std::endl;

  complex e = a * b;
  std::cout << "e = " << e.real << " + " << e.imag << "i" << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
  return 0;
}
