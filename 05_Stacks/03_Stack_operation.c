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
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){
    while (1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter a number for insert in the Stack : ");
                int data;
                scanf("%d",&data);
                push(data); 
                break;
            case 2:
                printf("Deleted data is %d\n.",pop());
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid number !!");
            }
    }
    return 0;
}