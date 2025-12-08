#include <stdio.h>

void selection_sort(int arr[],int n){
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    printf("Selection sort of enter array (Acending order): ");
    selection_sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
