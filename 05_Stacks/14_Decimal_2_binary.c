#include <stdio.h>
#include <stdlib.h>

//Converting decimal to binary using stack.

#define MAX 100
int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();

void decimal_to_binary(int num){
    int i = 2;
    int reminder;
    while (num != 0)
    {
        reminder = num%2;
        push(reminder);
        num = num/2;
    }
    while (top != -1)
    {
        printf("%d ",pop());
    }
}

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

// void print(){
//     if(top == -1){
//         printf("Stack Underflow !!");
//         return;
//     }
//     for (int i = 0; i <= top; i++)
//     {
//         printf("%d ",stack_arr[i]);
//     }
//     printf("\n");
// }

int main(){
    int number;
    printf("Enter a +ve number for convert Decimal to Binary : ");
    scanf("%d",&number);
    decimal_to_binary(number);
    
    // print(); //print in acending order.
   
    return 0;
}