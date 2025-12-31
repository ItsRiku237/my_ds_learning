#include <stdio.h>
#include <stdlib.h>

//Prime factorization using stack.

#define MAX 100
int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();

void prime_fact(int num){
    int i = 2;
    while (num != 1)
    {
        while (num%i == 0)
        {
            push(i);
            num = num/i;
        }
        i++;
    }
    while (top != -1)//print in decending order
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
    printf("Enter a +ve number : ");
    scanf("%d",&number);
    prime_fact(number);
    
    // print(); //print in acending order.
   
    return 0;
}