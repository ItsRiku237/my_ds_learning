// vdo no -123 DS by neso academy.
#include <stdio.h>
#include <stdlib.h>

// Reverse stack using 3 stack .
struct node
{
    int data;
    struct node *link;
};

void print(struct node** top);

void push(int data, struct node **top)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack Overflow !!");
        exit(1);
    }
    newNode->data = data;
    newNode->link = *top;
    *top = newNode;
}

int pop(struct node **top)
{
    int value;
    struct node *temp;
    temp = *top;

    value = temp->data;
    *top = temp->link;
    free(temp);
    temp = NULL;

    return value;
}

void reverse_stack(struct node **top)
{
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    // pushing onto temp stack_1.
    while (*top != NULL)
    {
        push(pop(top), &top1);
    }
    printf("Element of Original stack : ");
    print(top);
    printf("Element of temporary stack_1 : ");
    print(&top1);

    // pushing onto temp stack_2.
    while (top1 != NULL)
    {
        push(pop(&top1), &top2);
    }
    printf("Element of Original stack : ");
    print(top);
    printf("Element of temporary stack_1 : ");
    print(&top1);
    printf("Element of temporary stack_2 : ");
    print(&top2);

    // pushing onto original stack.
    while (top2 != NULL)
    {
        push(pop(&top2), top);
    }
    printf("Element of Original stack (Reverse Element) : ");
    print(top);
    printf("Element of temporary stack_1 : ");
    print(&top1);
    printf("Element of temporary stack_2 : ");
    print(&top2);
}

void print(struct node **top)
{
    struct node *temp;
    temp = *top;
    if (top == NULL)
    {
        printf("Stack underflow !!");
        return;
    }
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    int data;
    struct node *top = NULL;
    push(1, &top);
    push(2, &top);
    push(3, &top);
    printf("Element of Original stack : ");
    print(&top);

    reverse_stack(&top);
    return 0;
}