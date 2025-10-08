#include <stdio.h>
#include <stdlib.h>
// USE OF NULL POINTER.
int main()
{
    int *ptr;
    // dynamic memory allocation takes plase in heap memory
    // memory is allocatedor deallocate in randomly->heap
    ptr = (int *)malloc(2 * sizeof(int));
    // 1.
    if (ptr == NULL)
    {
        printf("Memory is not allocated .");
        // int *ptr = (int *)malloc(1000000000000); // Likely to fail
        // int *ptr = NULL; // Simulate malloc failure
    }
    else
    {
        printf("Memory is allocated successfully.\n");
    }
    ptr[0] = 10;
    ptr[1] = 20;
    printf("value : %d , %d\n ", ptr[0], ptr[1]);
    // 2.
    printf("%d\n", sizeof(NULL));

    free(ptr); // still pointing to deallocating memory location.
    // 3.
    ptr = NULL; // now ptr is no more dangling.
    if (ptr == NULL)
    {
        printf("ptr== NULL");
    }

    return 0;
}