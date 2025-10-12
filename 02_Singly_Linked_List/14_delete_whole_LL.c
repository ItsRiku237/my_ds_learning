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

struct node *del_whole_LL(struct node *head)
{

    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is already empty .");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->link;
            free(head);
            head = temp;
        }
    }
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

    printf("Before delete the LL :\n");
    print_data(head);

    head = del_whole_LL(head);

    printf("After delete the LL :\n");
    print_data(head);

    return 0;
}