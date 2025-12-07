// sse_dotprod.c
#include <emmintrin.h>   // SSE2 header; contains __m128 and intrinsics

float dotprod(float x[], float y[], int n) {
    __m128 sum_vec = _mm_setzero_ps();  // [0,0,0,0]

    int i;
    for (i = 0; i + 3 < n; i += 4) {
        // Load 4 floats from x and y
        __m128 xv = _mm_load_ps(&x[i]);   // assumes x is 16-byte aligned
        __m128 yv = _mm_load_ps(&y[i]);   // assumes y is 16-byte aligned

        // Multiply element-wise
        __m128 prod = _mm_mul_ps(xv, yv);

        // Accumulate
        sum_vec = _mm_add_ps(sum_vec, prod);
    }

    // Horizontal sum of sum_vec’s 4 lanes
    float temp[4] __attribute__((aligned(16)));
    _mm_store_ps(temp, sum_vec);

    float sum = temp[0] + temp[1] + temp[2] + temp[3];

    // (Optional) handle any leftover elements if n is not multiple of 4
    // but your test sizes are all multiples of 4 (powers of 2)
    for (; i < n; ++i) {
        sum += x[i] * y[i];
    }

    return sum;
}