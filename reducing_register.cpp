#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow);

const int N = 32;
const int M = 8;

inline void simd_radar_detection(int16_t * __restrict__ input, uint8_t * __restrict__ output)
{ 
    
    for (register int i = 0; i < N; i += 8) {
        
        __m128i sum = _mm_setzero_si128();

        for (register int j = 0; j < M; j++) {
            // Achtung hier kommt der Fehler:
            __m128i sample  = _mm_load_si128((__m128i *) (&input)) + i + j;
            sum = _mm_add_epi16(sum, sample);
        }
        __m128i threshold = _mm_set1_epi16(2000);
        __m128i mask = _mm_cmpgt_epi16(sum, threshold);

        uint16_t msk = _mm_movemask_epi8(mask);
        output[i] = (msk != 0);
    }
}

int main()
{

   int16_t input[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    uint8_t output[32];

    simd_radar_detection(input, output);
    std::cout<< "The Output:"<< std::endl; 
    for (int i = 0; i < N; i++) {
        std::cout << (int) output[i] << " ";    
    }
     return 0; }


//g++ reducing_rigester.cpp -o reducing_rigester -msse3
