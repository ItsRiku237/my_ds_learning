#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack is Overflow !!");
        return;
    }
    top++;
    stack_arr[top] = data;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow !!");
        exit(1);
    }
    int value = stack_arr[top];
    top = top - 1;
    return value;
}

void print()
{
    if (top == -1)
    {
        printf("Stack Underflow !!");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack_arr[i]);
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
    printf("\nDeleted data is %d .", pop());
    printf("\nDeleted data is %d .\n", pop());

    print();

    return 0;
}