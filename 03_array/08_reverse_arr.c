#include<stdio.h>

/*
Time complexity :
#LL:
del first node :LL{O(1)}
#array:
del first element : arr{O(n)}
*/

// time complexity {O(n)}

int main(){
    int size,temp;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    
    size =sizeof(a)/sizeof(a[0]);

    printf("Before reverse array is :");
    for (int i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    for (int i = 0; i < (size/2); i++)
    {
            temp = a[i];
            a[i] = a[size-i-1];
            a[size-i-1] = temp;
    }
    /*  for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // swap only when j is the mirror index AND ensure i < j
            //    so each pair is swapped exactly once 
            if (j == size - 1 - i && i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    */
    printf("After reverse array is :");

    for (int i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;

}