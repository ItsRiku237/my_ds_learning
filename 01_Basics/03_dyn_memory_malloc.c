#include <stdio.h>
#include <stdlib.h>

// malloc is initialized with some garbage value

int main()
{
    int n;
    printf("Enter size of the pointer : ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
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