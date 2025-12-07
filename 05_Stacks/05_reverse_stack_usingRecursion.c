#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int data){
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return top == -1;
}
/*A. reverse() goes DOWN (popping everything)
Call reverse() — frame names and what they do:

reverse() F1: temp = pop() → pops 40.
Stack now: [10,20,30].
reverse() calls itself.

reverse() F2: temp = pop() → pops 30.
Stack now: [10,20].
reverse() calls itself.

reverse() F3: temp = pop() → pops 20.
Stack now: [10].
reverse() calls itself.

reverse() F4: temp = pop() → pops 10.
Stack now: [] (empty, top == -1).
reverse() calls itself.

reverse() F5: sees isEmpty() true → returns immediately (base case).

Important: at this moment (right after F5 returns), the physical stack array 
is empty and top == -1. All popped values are stored in their respective temp
variables on the call stack inside F1..F4.

B. UNWINDING: each reverse() frame now calls insertAtBottom(temp) in reverse order

Unwind resumes at F4, then F3, F2, F1:

Resume F4: temp = 10. It calls insertAtBottom(10).
— Stack is empty now (top == -1). So the very first insertAtBottom sees isEmpty() == true and just does push(10).
Stack becomes: [10].

Resume F3: temp = 20. It calls insertAtBottom(20).
— Now the stack is [10] (non-empty). So insertAtBottom(20) does not push directly; it will pop items and recurse
 in order to place 20 at the bottom. After its internal recursion and pushes, the stack becomes [20,10] (bottom→top).

Resume F2: temp = 30. Calls insertAtBottom(30) → result: stack [30,20,10].

Resume F1: temp = 40. Calls insertAtBottom(40) → final stack [40,30,20,10].*/

void insertAtBottom(int x){
    if(isEmpty()){
        push(x);
        return;
    }
    int temp = pop();
    insertAtBottom(x);
    push(temp);
}

void reverse_stack(){
    if(isEmpty())return;
    int temp = pop();
    printf("%d ",temp);
    reverse_stack();
    insertAtBottom(temp);
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Stack element : ");
    reverse_stack();
    printf("\n");

    printf("Reverse stack order : ");
    while (!isEmpty())
    {
        printf("%d ",pop());
    }
    return 0;
}