#include <stdio.h>
#include <omp.h>

int main() {
    int total_sum = 0;  
    int n = 20;         

    #pragma omp parallel for reduction(+:total_sum)
    for (int i = 1; i <= n; i++) {
        total_sum += i;
    }

    printf("The sum of the first %d natural numbers is: %d\n", n, total_sum);

    return 0;
}
