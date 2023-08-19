#include <iostream>
#include <immintrin.h>
using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    __m256i vresult = _mm256_set1_epi64x(1);
    for (int i = 1; i <= n; i += 4) {
        __m256i vnum = _mm256_set_epi64x(i+3, i+2, i+1, i);
        vresult = _mm256_mul_epu32(vresult, vnum);
    }
    for (int i = n - (n%4) + 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    cout << "The factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}

