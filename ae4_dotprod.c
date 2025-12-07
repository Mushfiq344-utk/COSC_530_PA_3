// ae4_dotprod.c
float dotprod(float x[], float y[], int n) {
    float sum0 = 0.0f;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;

    for (int i = 0; i < n; i += 4) {
        sum0 += x[i]     * y[i];
        sum1 += x[i + 1] * y[i + 1];
        sum2 += x[i + 2] * y[i + 2];
        sum3 += x[i + 3] * y[i + 3];
    }

    return sum0 + sum1 + sum2 + sum3;
}