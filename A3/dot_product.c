#include "stdio.h"
#include "omp.h"
#include "stdlib.h"

#define n 10000000

void fill_rand(long a[], long size)
{
    #pragma omp parallel for
    for (long i = 0; i < size; i++)
        a[i] = rand() % 100;
}

void mergeAsc(long arr[], long left, long mid, long right)
{
    long n1 = mid - left + 1;
    long n2 = right - mid;

    long *L = (long *)malloc(n1 * sizeof(long));
    long *R = (long *)malloc(n2 * sizeof(long));

    for (long i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortAsc(long arr[], long left, long right)
{
    if (left < right)
    {
        long mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortAsc(arr, left, mid);
            #pragma omp section
            mergeSortAsc(arr, mid + 1, right);
        }

        mergeAsc(arr, left, mid, right);
    }
}

void mergeDesc(long arr[], long left, long mid, long right)
{
    long n1 = mid - left + 1;
    long n2 = right - mid;

    long *L = (long *)malloc(n1 * sizeof(long));
    long *R = (long *)malloc(n2 * sizeof(long));

    for (long i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortDesc(long arr[], long left, long right)
{
    if (left < right)
    {
        long mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortDesc(arr, left, mid);
            #pragma omp section
            mergeSortDesc(arr, mid + 1, right);
        }

        mergeDesc(arr, left, mid, right);
    }
}

int main()
{
    long *vector1 = (long *)malloc(n * sizeof(long));
    long *vector2 = (long *)malloc(n * sizeof(long));

    fill_rand(vector1, n);
    fill_rand(vector2, n);

    #pragma omp parallel sections
    {
        #pragma omp section
        mergeSortAsc(vector1, 0, n - 1);
        #pragma omp section
        mergeSortDesc(vector2, 0, n - 1);
    }

    long minProduct = 0;
    #pragma omp parallel for reduction(+ : minProduct)
    for (long i = 0; i < n; i++)
        minProduct += vector1[i] * vector2[i];

    printf("Dot product: %ld\n", minProduct);

    free(vector1);
    free(vector2);

    return 0;
}
