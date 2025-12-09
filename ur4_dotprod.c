float dotprod(float x[], float y[], int n)
{
    float sum = 0.0f;
    // Unroll by 4
    for (int i = 0; i < n; i += 4) {
        sum += x[i] * y[i];
        sum += x[i + 1] * y[i + 1];
        sum += x[i + 2] * y[i + 2];
        sum += x[i + 3] * y[i + 3];
    }

    return sum;
}
