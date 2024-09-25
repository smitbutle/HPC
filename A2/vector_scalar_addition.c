#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000

int main() {
    float scalar = 5.0;
    float *vector = (float *)malloc(SIZE * sizeof(float));
    float *result = (float *)malloc(SIZE * sizeof(float));

    for (int i = 0; i < SIZE; i++) {
        vector[i] = i * 1.0;
    }

    double start_time = omp_get_wtime();

    // Perform vector-scalar addition using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        result[i] = vector[i] + scalar;
    }

    double end_time = omp_get_wtime();
    
    double execution_time = end_time - start_time;
    printf("Execution time: %f seconds\n", execution_time);
    
    free(vector);
    free(result);

    return 0;
}
