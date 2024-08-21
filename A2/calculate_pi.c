#include <stdio.h>
#include <omp.h>

void main() {
    static long num_steps = 1000000;
    double step;
    int i;
    double x, pi, sum = 0.0;

    double start_time = omp_get_wtime();

    step = 1.0 / (double)num_steps;

    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < num_steps; i++) {
        x = ((double)(i + 0.5)) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = step * sum;

    double end_time = omp_get_wtime();
    double time_taken = end_time - start_time;

    printf("%.24f\n", pi);
    printf("Time taken(parallel): %f seconds\n", time_taken);

    return;
}
