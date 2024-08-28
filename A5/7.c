#include <stdio.h>

#define ARRAY_SIZE 1000

int main() {
    int array[ARRAY_SIZE];
    int total_sum = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        total_sum += array[i];
    }

    printf("Serial sum: %d\n", total_sum);

    return 0;
}
