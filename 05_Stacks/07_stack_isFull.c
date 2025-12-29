#include <stdio.h>

#define MAX 5
int stack_arr[MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack is Overflow !!");
        return;
    }
    top++;
    stack_arr[top] = data;
    
}

void print(){
    if(top == -1){
        printf("Stack Underflow !!\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    print();
    push(30);
    print();
    return 0;
}