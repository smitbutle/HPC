#include <stdio.h>
#include <omp.h>

long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    long fib1 = 0, fib2 = 1, fib;

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 2; i <= n; i++) {
                #pragma omp task firstprivate(fib1, fib2)
                {
                    fib = fib1 + fib2;
                    fib1 = fib2;
                    fib2 = fib;
                }
                #pragma omp taskwait 
            }
        }
    }
    
    return fib2;
}

int main() {
    int n = 100000;
    
    long result = fibonacci_iterative(n);
    printf("Fibonacci number at position %d is %ld\n", n, result);
    
    return 0;
}
