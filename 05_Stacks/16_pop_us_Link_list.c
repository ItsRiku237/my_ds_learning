#include <stdio.h>
#include <stdlib.h>

// Linked list implementation of stack.
// push using link list.
struct node
{
    int data;
    struct node *link;
} *top = NULL;

void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack Overflow !!");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

void pop(){
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack underflow !!");
        return;
    }
    top = top->link;
    free(temp);
    temp = NULL;
}

void print()
{
    struct node *temp;
    temp = top;
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
    while (1)
    {
        printf("1.Push\n2.pop\n3.Display\n4.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number for insert in the Stack : ");
            int data;
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
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