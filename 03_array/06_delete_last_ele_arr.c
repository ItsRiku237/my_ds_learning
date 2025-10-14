#include<stdio.h>

/*
Time complexity :
#LL:
delete at end :LL{O(n)}
#array:
delete at end : arr{O(1)}
*/

// time complexity {O(1)}
int main(){
    int size;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    
    size =sizeof(a)/sizeof(a[0]);
    int last_ele_ind = size-1 ;

    for (int i = 0; i <last_ele_ind ; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;

}