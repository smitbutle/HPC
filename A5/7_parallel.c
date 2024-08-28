#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000

int main() {
    int array[ARRAY_SIZE];
    int total_sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1; 
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            #pragma omp atomic
            total_sum += array[i];
        }
    }

    printf("Parallel sum (with atomic): %d\n", total_sum);

    return 0;
}
