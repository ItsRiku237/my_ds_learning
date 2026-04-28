#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sort a given set of n integer elements using Selection Sort method and
// compute its time complexity. Run the program for varied values of n> 5000 
// and record the time taken to sort. The elements can be read from a file or can
// be generated using the random number generator. Demonstrate how the brute force
// method works along with its time complexity analysis: worst case, average case and best case.


void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}


int main()
{
    int *arr, n;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements (n > 5000): ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    generateRandom(arr, n);

    start = clock();
    selectionSort(arr, n);
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time);

    free(arr);

    return 0;
}


// Time Complexity
// Case	Time Complexity
// Best Case	O(n²)
// Average Case	O(n²)
// Worst Case	O(n²)


// Conclusion
// Selection Sort is a brute force algorithm
// It is simple but inefficient for large data
// Time complexity is always O(n²)
//Slow for large data