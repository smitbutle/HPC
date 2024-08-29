#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_vector_multiply(int **A, int *x, int *y, int m, int n) {
    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        y[i] = 0;
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    int m = 5000, n = 5000;
    int **A = (int **)malloc(m * sizeof(int *));
    int *x = (int *)malloc(n * sizeof(int));
    int *y = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) A[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = i + j;

    for (int i = 0; i < n; i++)
        x[i] = i;

    double start_time = omp_get_wtime();
    matrix_vector_multiply(A, x, y, m, n);
    double end_time = omp_get_wtime();

    printf("Matrix-vector multiplication completed in %f seconds.\n", end_time - start_time);

    // Free memory
    for (int i = 0; i < m; i++) free(A[i]);
    free(A);
    free(x);
    free(y);

    return 0;
}
