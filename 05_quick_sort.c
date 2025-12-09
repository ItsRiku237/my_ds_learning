#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b= temp;
}

int partion(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pi = partion(arr,low,high);
        quick_sort(arr,low,(pi - 1));
        quick_sort(arr,pi+1,high);
    }
}

int main(){
    int n;
    printf("Enter number of array element : ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element : ");
        scanf("%d",&arr[i]);
    }
    printf("Insertion sort of enter array (Acending order): ");
    quick_sort(arr,0,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}