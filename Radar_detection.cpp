#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <iomanip>
using namespace std; 
const int N = 32;
const int M = 8;
void simd_radar_detection(int16_t *input, uint8_t *output)
{
    for (int i = 0; i < N; i += M) {
        __m128i sum = _mm_setzero_si128();

        for (int j = 0; j < M; j++) {
            __m128i sample = _mm_load_si128((__m128i *) (input + i + j));
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
    int16_t input[N] = {0, 1, 2, 3, 551, 56, 6, 74, 878, 9, 10, 11, 2, 103, 104, 15,
                        16, 17, 18, 19, 20, 21, 77, 23, 24, 5, 6, 7, 8, 29, 30, 31};
    uint8_t output[N];

    simd_radar_detection(input,output); 
    
     cout << "Output: ";
    for (int i = 0; i < N; i++) {
        cout << hex << setw(2) << setfill('0') << (int) output[i] << " ";
    }
    cout << endl;
    return 0; } 
