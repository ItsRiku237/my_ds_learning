#include <stdio.h>
#include <stdlib.h>

// Linked list implementation of stack.
// push using link list.

struct node
{
    int data;
    struct node *link;
} *top = NULL;

int isFull(struct node *newNode)
{
    if (newNode == NULL)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == NULL)
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
        printf("Stack Overflow !!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("Stack underflow !!\n");
        // exit(1);//it fail the while loop
        return 0;
    }
    int value = top->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack underflow !!\n");
        // exit(1);//it fail the while loop
        return;
    }
    printf("Peek element of the stack is : %d/n", top->data);
}

void print()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("Stack underflow !!/n");
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
    while (1)
    {
        printf("1.Push\n2.pop\n3.Peek Element\n4.Display\n5.Exit\n");
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
            peek();
            break;//when i am not use break simply it run next case 4.
        case 4:
            print();
            break;
        case 5:
            exit(0);
        default:
            printf("Enter valid number !!");
        }
    }
    return 0;
}