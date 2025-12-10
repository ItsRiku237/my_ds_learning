// Create an array of size '8' and insert the
// element <10,12,14,16,18> into the array
// it.display the current elements
// in. Then, add an element 20 in the 3rd position of the array.
// Display the contents of the
//  modified array (Required output array (10,12,20,14,16,18)

#include <stdio.h>

int main()
{
    int arr[8]; // Step i: Create array of size 8
    int n = 5;  // Currently we have 5 elements

    // Insert initial 5 elements
    arr[0] = 10;
    arr[1] = 12;
    arr[2] = 14;
    arr[3] = 16;
    arr[4] = 18;

    // Step ii: Display current elements
    printf("Current array elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Step iii: Insert 20 at 3rd position (index 2)
    int pos = 2; // Index where to insert
    int element = 20;

    // Shift elements to the right
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element; // Insert new element
    n++;                // Increase count

    // Step iv: Display modified array
    printf("\nModified array elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
