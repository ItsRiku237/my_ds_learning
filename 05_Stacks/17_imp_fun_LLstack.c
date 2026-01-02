#include <stdio.h>
#include <stdlib.h>

// Linked list implementation of stack.
// push using link list.
struct node
{
    int data;
    struct node *link;
} *top = NULL;

int isFull(struct node* newNode){
    if(newNode == NULL)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}

void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (isFull(newNode))
    {
        printf("Stack Overflow !!");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop(){
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("Stack underflow !!");
        exit(1);
    }
    int value =top->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

void peek(){
    if (isEmpty())
    {
        printf("Stack underflow !!");
        exit(1);
    }
    printf("Peek element of the stack is : %d",top->data);
}

void print()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("Stack underflow !!");
        return;
    }
    printf("The Stack Element are : ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
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
    
    peek();
    print();
    printf("Deleted data is %d .",pop());
    printf("Deleted data is %d .",pop());

    print();
    peek();
    return 0;
}