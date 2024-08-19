#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_POINTS 10000000  

int main() {
    int points_inside_circle = 0;
    double x, y;

    double start_time = omp_get_wtime();

    // Use OpenMP to parallelize the loop
    #pragma omp parallel for private(x, y) reduction(+:points_inside_circle) num_threads(16)
    for (int i = 0; i < NUM_POINTS; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1.0) {
            points_inside_circle++;
        }
    }

    // Calculate Pi approximation
    double pi = 4.0 * points_inside_circle / NUM_POINTS;

    double end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    // Print the result
    printf("Calculated Pi = %.6f\n", pi);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}
