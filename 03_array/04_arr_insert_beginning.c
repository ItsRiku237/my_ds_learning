#include<stdio.h>

/*
Time complexity :
#LL:
add at begining :LL{O(1)}
#array:
add at begining : arr{O(n)}
*/

// time complexity {O(n)}
int insert_beginning_full(int a[],int b[],int size){
    for (int i = 0; i < size; i++)
        b[i+1]=a[i];
    
    int item;
    printf("Enter the element : ");
    scanf("%d",&item);
    b[0]= item ;
    size++;

    return size ;
}

// time complexity {O(n)}
int insert_beginning_not_full(int a[],int n){
    for (int i = n-1 ; i >=0; i--)
        a[i+1]=a[i];
    
    int item;
    printf("Enter the element : ");
    scanf("%d",&item);
    a[0]= item ;
    n++;

    return n ;
}

void print_data(int b[],int n){
    for (int i = 0; i <n ; i++)
        printf("%d ",b[i]);
}

int main(){
    int n;
    printf("Enter no. of element : ");
    scanf("%d",&n);
    int a[10] ,size;

    for (int i = 0; i <n ; i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    
    size =sizeof(a)/sizeof(a[0]);

    if(size == n){
        printf("Array is full!!\n");
        int b[size+2];
        n = insert_beginning_full(a,b,n);
        print_data(b,n);
    }
    else{
        n = insert_beginning_not_full(a,n);
        print_data(a,n);
    }
    
    return 0;

}