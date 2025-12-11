#include <stdio.h>

// Binary search
// It only work in sorted  array.

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

    int found = 0, mid, low = 0, high = n - 1;

    // for (int i = 0; i < n; i++) //This runs n times even when low > high
    // (which is wrong for binary search).

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            printf("Element %d is found in position %d (index %d ).", key, mid + 1, mid);
            found = 1;
            break;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
    }
    if (!found)
    {
        printf("Element %d is not found .", key);
    }
    //  if (found==0)
    // {
    //     printf("Element %d is not found .",key);
    // }
}