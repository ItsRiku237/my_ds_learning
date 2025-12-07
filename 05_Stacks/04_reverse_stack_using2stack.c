#include <stdio.h>
#define SIZE 5

int stack1[SIZE];
int stack2[SIZE];

int top1 = -1;
int top2 = -1;

void push1(int data){
    stack1[++top1] = data;
}
void push2(int data){
    stack2[++top2] = data;
}

int pop1(){
    return stack1[top1--];
}

int pop2(){
    return stack2[top2--];
}

int isEmpty1(){
    return top1 == -1;
}

int isEmpty2(){
    return top2 == -1;
}

void reverse_stack(){
    while (!isEmpty1())
    {
        int value;
        value = pop1();
        printf("%d ",value);
        push2(value);
    }
}

int main(){
    push1(10);
    push1(20);
    push1(30);
    push1(40);
    push1(50);

    printf("Stack element : ");
    reverse_stack();
    printf("\n");

    printf("Reverse stack order : ");
    while (!isEmpty2())
    {
        printf("%d ",pop2());
    }
    return 0;
}