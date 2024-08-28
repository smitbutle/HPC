#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiply_serial(int n, double** A, double** B, double** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n = 100; // Matrix size
    // Allocate matrices
    double** A = (double**)malloc(n * sizeof(double*));
    double** B = (double**)malloc(n * sizeof(double*));
    double** C = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
        B[i] = (double*)malloc(n * sizeof(double));
        C[i] = (double*)malloc(n * sizeof(double));
    }

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    clock_t start = clock();
    matrix_multiply_serial(n, A, B, C);
    clock_t end = clock();

    printf("Serial execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
