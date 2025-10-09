#include <stdio.h>
#include <stdlib.h>

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

    int m;
    printf("Enter extra size of the pointer : ");
    scanf("%d", &m);
    ptr = (int *)realloc(ptr, m * sizeof(int));
    for (int i = n; i < n + m; i++)
    {
        printf("Enter a integer : ");
        scanf("%d", ptr + i);
    }
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", *(ptr + i));
    }
}