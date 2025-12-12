#include <stdio.h>

int main(){
    int arr[] = {1, 2,3, 4, 5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]); // Current number of elements
    int pos = 3; // Index where you want to insert (second position)
    // int element = 3;

    for(int i=(pos-1); i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    for(int i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
}