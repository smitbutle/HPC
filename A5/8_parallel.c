#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    long long total_sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1; 
    }

    #pragma omp parallel reduction(+:total_sum)
    {
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            total_sum += array[i];
        }
    }

    printf("Parallel sum (with reduction): %lld\n", total_sum);

    return 0;
}
