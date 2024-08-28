#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
omp_lock_t lock;

void producer(int id) {
    int produced_item;
    for (int i = 0; i < 20; i++) { // Each producer produces 20 items
        produced_item = rand() % 100;
        
        omp_set_lock(&lock);
        while (count == BUFFER_SIZE) {
            // Buffer is full, wait
            omp_unset_lock(&lock);
            omp_set_lock(&lock);
        }

        buffer[count] = produced_item;
        count++;
        printf("Producer %d produced %d\n", id, produced_item);
        omp_unset_lock(&lock);
    }
}

void consumer(int id) {
    int consumed_item;
    for (int i = 0; i < 20; i++) { // Each consumer consumes 20 items

        omp_set_lock(&lock);
        while (count == 0) {
            // Buffer is empty, wait
            omp_unset_lock(&lock);
            omp_set_lock(&lock);
        }

        consumed_item = buffer[count - 1];
        count--;
        printf("Consumer %d consumed %d\n", id, consumed_item);
        omp_unset_lock(&lock);
    }
}

int main() {
    omp_init_lock(&lock);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            producer(1);
        }
        #pragma omp section
        {
            consumer(1);
        }
        #pragma omp section
        {
            producer(2);
        }
        #pragma omp section
        {
            consumer(2);
        }
    }

    omp_destroy_lock(&lock);
    return 0;
}
