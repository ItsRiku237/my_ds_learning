#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX-1){
        printf("Stack is Overflow !!");
        return;
    }
    top++;
    stack_arr[top] = data;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow !!");
        exit(1);
    }
    int value = stack_arr[top];
    top--;
    return value;
}

void print(){
    if(top == -1){
        printf("Stack Underflow !!");
        return;
    }
    for (int i = 0; i < MAX; i++)
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
    printf("Deleted data is %d .",pop());
    printf("Deleted data is %d .",pop());

    print();

    return 0;
}