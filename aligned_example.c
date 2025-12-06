#include <stdio.h>
#include <stdint.h>
#include <emmintrin.h>

int main() {

    // NOT aligned — compiler chooses any address
    float normal[4] = {1,2,3,4};

    // Aligned to 16 bytes
    float aligned[4] __attribute__((aligned(16))) = {1,2,3,4};

    printf("Address of normal  = %p\n", (void*)normal);
    printf("Address of aligned = %p\n", (void*)aligned);

    // Test whether they are aligned
    printf("normal %% 16 = %ld\n", (uintptr_t)normal % 16);
    printf("aligned %% 16 = %ld\n", (uintptr_t)aligned % 16);

    return 0;
}