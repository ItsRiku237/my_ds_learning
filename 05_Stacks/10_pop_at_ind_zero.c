#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack_arr[MAX];
int first = -1;

void push(int data){
    first +=1;
    if(first == MAX){
        printf("Stack is Overflow !!");
        return;
    }
    for (int i = first; i > 0; i--)
        stack_arr[i] = stack_arr[i-1]; 
    
    stack_arr[0] = data;
}

int pop(){
    if(first == -1){
        printf("Stack Underflow !!");
        exit(1);
    }
    int value = stack_arr[0];
    for (int i = 0; i < first; i++)
    {
        stack_arr[i] = stack_arr[i+1];
    }
    first -=1;
    return value;
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
    
    print();
    printf("Deleted data is %d .\n",pop());
    printf("Deleted data is %d .\n",pop());

    print();

    return 0;
}