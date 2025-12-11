#include <stdio.h>

int binary_sear_recur(int arr[], int key, int n, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return binary_sear_recur(arr, key, n, mid + 1, high);
        }
        else if (key < arr[mid])
        {
            return binary_sear_recur(arr, key, n, low, mid - 1);
        }
        else
        {
            return -1;
        }
    }
}

// Binary search with the help of recursion
void main()
{
    int n;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element of the array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element which is finding : ");
    scanf("%d", &key);

    int mid, low = 0, high = n - 1, index;

    index = binary_sear_recur(arr, key, n, low, high);

    if (index != -1)
    {
        printf("Element %d is found in position %d (index %d ).", key, index + 1, index);
    }

    else if (index == -1)
    {
        printf("Element %d is not found !", key);
    }
}