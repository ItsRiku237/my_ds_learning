#include<stdio.h>

/*
Time complexity :
#LL:
add at begining :LL{O(1)}
#array:
add at begining : arr{O(n)}
*/

// time complexity {O(n)}
// Insert when array is full (using new array)
int insert_at_pos_full(int a[],int b[],int size){
    int data, pos;
    printf("Enter position for insert : ");
    scanf("%d",&pos);
    printf("Enter the element : ");
    scanf("%d",&data);

    int index = --pos;// 1-based to 0-based index(use pos when int i = 1 in for loop)
    for (int i = 0; i < index; i++)
        b[i]=a[i];
    
    b[index] =data;

    for (int i = index+1 ,j =index ; i <size+1,j<size; i++,j++)
        b[i]=a[j];

    return size+1 ;
}

// time complexity {O(n)}
// Insert when array is not full (in the same array)
int insert_at_pos_not_full(int a[],int n){
    int data, pos,index;
    printf("Enter position for insert : ");
    scanf("%d",&pos);
    printf("Enter the element : ");
    scanf("%d",&data);

    index = pos -1;
    // Shift elements right from the end
    for (int i = n-1 ; i >=index; i--)
        a[i+1]=a[i];
    
    a[index] = data;

    return n+1 ;
}

void print_data(int b[],int n){
    for (int i = 0; i <n ; i++)
        printf("%d ",b[i]);
}

int main(){
    int n;
    printf("Enter no. of element : ");
    scanf("%d",&n);
    int a[5] ,size;

    for (int i = 0; i <n ; i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    
    size =sizeof(a)/sizeof(a[0]);

    if(size == n){
        printf("Array is full!!\n");
        int b[size+2];
        n = insert_at_pos_full(a,b,n);
        print_data(b,n);
    }
    else{
        n = insert_at_pos_not_full(a,n);
        print_data(a,n);
    }
    
    return 0;

}