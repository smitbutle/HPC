#include <stdio.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    long long total_sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1;
    }
 
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        total_sum += array[i];
    }

    printf("Sequential sum: %lld\n", total_sum);

    return 0;
}
