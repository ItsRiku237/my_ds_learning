#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* Function to swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} /* Partition function */
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int main()
{
    int n;
    clock_t start, end;
    double time_taken;
    printf("Enter number of elements (n > 5000): ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int)); /* Generate random numbers */
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
    }
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements = %f seconds\n", n, time_taken);
    
    free(a);
    return 0;
}