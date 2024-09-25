#include <omp.h>
#include <stdio.h>

#define N 1000

void do_work(int start, int end, int *array)
{
    for (int i = start; i < end; i++)
    {
        array[i] = i * i; // Example computation
    }
}

int main()
{
    int array[N];

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            do_work(0, N / 2, array);
            printf("Section 1 completed\n");
        }

        #pragma omp section
        {
            do_work(N / 2, N, array);
            printf("Section 2 completed\n");
        }

        #pragma omp section
        {
            printf("No wait section\n");
        }
    }

    printf("All sections completed\n");

    return 0;
}
