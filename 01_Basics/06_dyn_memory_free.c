#include <stdio.h>
#include <stdlib.h>

int *input()
{
    int n;
    // printf("Enter no. of element :");
    // scanf("%d",&n);
    int *ptr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", ptr + i);
    }
    return ptr;
}

int main()
{
    int *ptr;
    ptr = input();
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += *(ptr + i);
    }
    printf(" sum of no. is : %d .\n", sum);
    printf("%d\n", ptr);
    printf("%d\n", *ptr);
    free(ptr);            // releazing the memory
    printf("%d\n", *ptr); // dangling pointer
    printf("%d\n", ptr);
    ptr = NULL;
    printf("%d\n", ptr);
    printf("%d\n", *ptr);
}