#include <stdio.h>
int lin_sear_recur(int arr[], int key, int n, int index)
{
    if (index >= n)
    {
        return -1;
    }

    else if (key == arr[index])
    {
        return index;
    }

    return lin_sear_recur(arr, key, n, index + 1);
}

// Linear search eith the help of recursion.
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
    int index;
    index = lin_sear_recur(arr, key, n, 0);
    if (index != -1)
    {
        printf("Element %d is found in position %d (index %d ).", key, index + 1, index);
    }
    else if (index== -1)
    {
        printf("Element %d is not found !",key);
    }
    
}