#include <stdio.h>
#include <omp.h>

#define SIZE 10000

int main() {
    float scalar = 5.0;
    float vector[SIZE];
    float result[SIZE];

    for (int i = 0; i < SIZE; i++) {
        vector[i] = i * 1.0;
    }

    double start_time = omp_get_wtime();

    // Perform vector-scalar addition using OpenMP
    // #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        result[i] = vector[i] + scalar;
    }

    double end_time = omp_get_wtime();
    
    double execution_time = end_time - start_time;
    printf("Execution time: %f seconds\n", execution_time);

    for (int i = 0; i < 10; i++) {
        printf("result[%d] = %.2f\n", i, result[i]);
    }

    return 0;
}
