#include<stdio.h>

/*
Time complexity :
#LL:
with traversal:LL{O(n)} ,without traversal : LL{O(1)}
#array:
arr is not full : arr{O(1)} , arr is full : arr{O(n)}
*/

// time complexity {O(n)}
int add_to_end(int a[],int b[] ,int size,int freepose){
    for (int i = 0; i < size; i++)
        b[i]=a[i];

    int item;
    printf("Enter the element : ");
    scanf("%d",&item);
    b[freepose]= item ;
    
    freepose++;

    return freepose ;
}

void print_data(int b[],int freepose){
    for (int i = 0; i <freepose ; i++)
        printf("%d ",b[i]);
}

int main(){
    int n;
    printf("Enter no. of element : ");
    scanf("%d",&n);
    int a[n], freepose ,size;

    for (int i = 0; i <n ; i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    
    size =sizeof(a)/sizeof(a[0]);
    freepose = n;

    if(size == n){
        printf("Array is full!!\n");
        int b[size+2];
        freepose = add_to_end(a,b,size,freepose);
        print_data(b,freepose);
    }
    
    return 0;

}