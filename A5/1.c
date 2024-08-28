// Q1. Write an OpenMP program such that, it should print the name of your family members, such that the names should come from different threads/cores. Also print the respective job id.

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    char *names[] = {"Smit", "Nimit", "Sandeep", "Utkarsha", "Akanksha", "Usha", "Sarthak", "Achyut"};

    #pragma omp parallel for
    for(int i = 0;i < 8;i++)
    {
        #pragma omp task
        {
            printf("Name: %s, Job ID: %d\n", names[i], omp_get_thread_num());
        }
    }   
}