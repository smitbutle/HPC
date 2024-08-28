#include <stdio.h>
#include <omp.h>

int main(void)
{
    #pragma omp parallel
    {
        printf(" Hello(%d)", omp_get_thread_num());
        printf(" world(%d)", omp_get_thread_num());
    }
    return 0;
}
