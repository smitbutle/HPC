#include <stdio.h>
#include <omp.h>

int main() {
    int Aryabhatta = 10;

    #pragma omp parallel firstprivate(Aryabhatta)
    {
        int tid = omp_get_thread_num();  // Get the thread ID
        Aryabhatta = 10;  

        int result = tid * Aryabhatta;
        printf("Thread %d: Result = %d\n", tid, result);
    }

    return 0;
}
