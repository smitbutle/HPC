#include <stdio.h>
#include <omp.h>

int main() {
    int sum_of_squares = 0;

    #pragma omp parallel reduction(+:sum_of_squares)
    {
        int tid = omp_get_thread_num();
        int square = tid * tid;
        printf("Thread %d: Square = %d\n", tid, square);
        sum_of_squares += square;
    }

    printf("Sum of squares of thread IDs: %d\n", sum_of_squares);

    return 0;
}
