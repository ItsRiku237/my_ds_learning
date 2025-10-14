#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// time complexity {O(1)}
struct node *add_to_end(struct node *ptr, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;

    return temp;
}

struct node *reverse(struct node *head)
{

    struct node *prev = NULL;
    struct node *next = NULL;

    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;

    return head;
}

int print_data(struct node *head)
{

    if (head == NULL)
    {
        printf("Linked List deleted succesfully.");
        return 0;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 23;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_to_end(ptr, 32);
    ptr = add_to_end(ptr, 42);
    ptr = add_to_end(ptr, 52);
    ptr = head;

    printf("Before Reverse the LL :\n");
    print_data(head);

    head = reverse(head);

    printf("After Reverse the LL :\n");
    print_data(head);

    return 0;
}