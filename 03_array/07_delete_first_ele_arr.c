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
    int size;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    
    size =sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < size; i++)
    {
        a[i]=a[i+1];
    }
    //shift one-one element towards 1st index then decrement size to size-1

    size = size-1;

    for (int i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;

}