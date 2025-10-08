#include <stdio.h>

int main()
{
    int n = 10;
    // void *ptr = &n;

    // printf("n = %d .", *(int *)ptr);//it can be typecasted to any data type.

    // printf("n = %d .",*ptr);
    // // we can not derefernce a void pointer.
    void *ptr = &n;
    printf("%d\n", *(int *)ptr); // value of n
    printf("%d\n", (int *)ptr);  // address of n
    printf("%d\n", ptr);         // address of n (no error show)
    // printf("%d\n",*ptr); // value of n (error show)
    return 0;
}
