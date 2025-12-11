#include <stdio.h>

int main() {
    int arr[100] = {1, 2, 4, 5};  // Initial array with some elements
    int n = 4; // Current number of elements
    int pos = 1; // Index where you want to insert (second position)
    int element = 3;

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element
    arr[pos] = element;
    n++; // Increase the size

    // Print the updated array
    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
