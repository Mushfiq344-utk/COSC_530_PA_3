#include <emmintrin.h>

float dotprod(float x[], float y[], int n) {
    __attribute__ ((aligned(16))) float zero[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    __m128 sum_vec = _mm_load_ps(zero);

    int i;
    for (i = 0; i < n; i += 4) {
        // Load 4 floats from x and y
        __m128 x_vec = _mm_load_ps(&x[i]);   
        __m128 y_vec = _mm_load_ps(&y[i]);   

        // Multiply element-wise
        __m128 prod_vec = _mm_mul_ps(x_vec, y_vec);

        // Accumulate
        sum_vec = _mm_add_ps(sum_vec, prod_vec);
    }

    // Horizontal sum of sum_vec’s 4 lanes
    float sums[4] __attribute__((aligned(16)));
    _mm_store_ps(sums, sum_vec);

    float sum = sums[0] + sums[1] + sums[2] + sums[3];

    return sum;
}