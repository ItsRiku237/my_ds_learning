#include <stdio.h>
#include <stdlib.h>

// Palindrome chaker.
struct node
{
    char data;
    struct node *link;
} *top = NULL;

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void push(char data)
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

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow !!");
        exit(1);
    }

    struct node *temp = top;
    char ch = temp->data;
    top = top->link;
    free(temp);
    return ch;
}

void palindrome_check(char *s)
{
    int i = 0;
    while (s[i] != 'x')
    {
        push(s[i]);
        i++;
    }
    i++;
    while (s[i])
    {
        if (isEmpty() || s[i] != pop())
        {
            printf("Not a Palindrome.");
            exit(1);
        }
        i++;
    }
    printf("Enter string is a Palindrome.");
}

int main()
{
    char s[100];
    printf("Please Enter the String : ");
    scanf("%s", s);

    palindrome_check(s);
    return 0;
}