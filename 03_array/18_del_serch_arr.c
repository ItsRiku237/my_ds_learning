#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // Current number of elements
    int ele = 5;                          // Index where you want to insert (second position)
    int ind ;
    // int element = 3;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == ele)
    //     {
    //         ind = i;
    //     }
    // }
    // for (int i = ind; i < n - 1; i++)
    // {
    //     arr[i] = arr[i + 1];
    // }
    // n--;

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            found = 1;
            // Shift elements to the left
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--; // Reduce size
            break; // Exit loop after deleting the first match
        }
    }

    if (found) {
        printf("Updated array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Element not found in array.");
    }

    return 0;
}