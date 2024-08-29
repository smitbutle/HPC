#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_multiply(int **A, int **B, int **C, int m, int n, int p) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m = 500, n = 500, p = 500;
    int **A = (int **)malloc(m * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **C = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) A[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) B[i] = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < m; i++) C[i] = (int *)malloc(p * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = i + j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            B[i][j] = i - j;

    double start_time = omp_get_wtime();
    matrix_multiply(A, B, C, m, n, p);
    double end_time = omp_get_wtime();

    printf("Matrix multiplication completed in %f seconds.\n", end_time - start_time);

    // Free memory
    for (int i = 0; i < m; i++) free(A[i]);
    for (int i = 0; i < n; i++) free(B[i]);
    for (int i = 0; i < m; i++) free(C[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}
