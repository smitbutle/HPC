#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_addition(double **A, double **B, double **C, int N, int M) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    double **A = malloc(N * sizeof(double *));
    double **B = malloc(N * sizeof(double *));
    double **C = malloc(N * sizeof(double *));
    for (int i = 0; i < N; ++i) {
        A[i] = malloc(M * sizeof(double));
        B[i] = malloc(M * sizeof(double));
        C[i] = malloc(M * sizeof(double));
    }

    // Initialize matrices A and B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = i + j; // Example values
            B[i][j] = i - j; // Example values
        }
    }

    double start_time = omp_get_wtime();
    matrix_addition(A, B, C, N, M);
    double end_time = omp_get_wtime();

    printf("Time taken for matrix addition: %f seconds\n", end_time - start_time);

    // Free allocated memory
    for (int i = 0; i < N; ++i) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
