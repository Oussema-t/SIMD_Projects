#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
const int N = 32;
const int M = 8;

void simd_radar_detection(int16_t *input, uint8_t *output)
{
    for (int i = 0; i < N; i += M) {
        __m128i sum = _mm_setzero_si128();

        for (int j = 0; j < M; j++) {
            __m128i sample = _mm_load_si128((__m128i *) (&input)) + i + j;
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

    uint8_t output[N];

    simd_radar_detection(input, output);
    std::cout<< "The Output:"<< std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << (int) output[i] << " ";    
    }


    return 0;
}

