#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define VECTOR_SIZE 200
#define CHUNK_SIZE 5

void vector_addition(double *vec, double scalar) {
    omp_set_schedule(omp_sched_dynamic,CHUNK_SIZE);
    #pragma omp parallel for
    for (int i = 0; i < VECTOR_SIZE; ++i) {
        vec[i] += scalar;
    }
}

int main() {

    double vec[VECTOR_SIZE];
    double scalar = 5.0;

    for (int i = 0; i < VECTOR_SIZE; ++i) {
        vec[i] = i; // Example values
    }

    double start_time = omp_get_wtime();
    vector_addition(vec, scalar);
    double end_time = omp_get_wtime();

    printf("Time taken for vector addition: %f seconds\n", end_time - start_time);

    return 0;
}
