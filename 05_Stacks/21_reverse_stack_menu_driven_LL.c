// vdo no -123 DS by neso academy.
#include <stdio.h>
#include <stdlib.h>

// Reverse stack using 3 stack .
struct node
{
    int data;
    struct node *link;
};

void print(struct node **top);

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
    struct node *top = NULL;
    
   
    while (1)
    {
        printf("1.Push\n2.pop\n3.Reverse stack\n4.Display\n5.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number for insert in the Stack : ");
            int data;
            scanf("%d", &data);
            push(data,&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            reverse_stack(&top);
        case 4:
            print(&top);
            break;
        case 5:
            exit(0);
        default:
            printf("Enter valid number !!");
        }
    }
    return 0;
}