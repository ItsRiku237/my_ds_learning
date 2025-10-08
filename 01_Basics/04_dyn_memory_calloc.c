#include <stdio.h>
#include <stdlib.h>

// memory allocated by calloc is initili8zed by zero.
//  malloc and calloc both are return null when sufficient memory is not avilable in heap.

int main()
{
    int n;
    printf("Enter size of the pointer : ");
    scanf("%d", &n);
    int *ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory is not allocated .");
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter a integer : ");
        scanf("%d", ptr + i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
}