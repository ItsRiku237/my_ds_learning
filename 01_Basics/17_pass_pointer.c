#include<stdio.h>

void display(int *p,int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ,",*p++);
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int *ptr=arr;
    display(ptr,n);
    return 0;
}