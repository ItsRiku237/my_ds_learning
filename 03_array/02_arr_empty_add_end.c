#include<stdio.h>

// time complexity {O(1)}
int add_to_end(int a[],int n,int freepose){
    int item;
    printf("Enter the element : ");
    scanf("%d",&item);

    a[freepose] = item;
    freepose++;
    return freepose ;
}

void print_data(int a[],int freepose){
    for (int i = 0; i <freepose ; i++)
        printf("%d ",a[i]);
}

int main(){
    int a[10], n, freepose;

    printf("Enter no. of element : ");
    scanf("%d",&n);

    for (int i = 0; i <n ; i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    
    freepose = n;
    freepose = add_to_end(a,n,freepose);
    print_data(a,freepose);
    return 0;

}