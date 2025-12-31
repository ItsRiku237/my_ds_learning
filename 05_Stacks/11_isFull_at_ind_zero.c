#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack_arr[MAX];
int first = -1;

int isFull(){
    if(first == MAX-1)
        return 1;
    else
        return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack is Overflow !!\n");
        return;
    }
    first +=1;
    for (int i = first; i > 0; i--)
        stack_arr[i] = stack_arr[i-1]; 
    
    stack_arr[0] = data;
}


void print(){
    if(first == -1){
        printf("Stack Underflow !!");
        return;
    }
    for (int i = 0; i <= first; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){
    push(5); 
    push(10); 
    push(15); 
    push(20); 
    push(25); 
    push(30); 
    
    print();
    
    return 0;
}