#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *add_to_empty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;

    return head;
}

struct node *add_at_beg(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head != NULL)
    {
        head->prev = temp;
        temp->next = head;
    }

    head = temp;

    return temp;
}

struct node *add_at_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

    return head;
}


struct node *add_at_before_pos(struct node *head, int data, int pos)
{
    
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        printf("List is empty, cannot insert before position %d\n", pos);
        return head;
    }

    if (pos == 1) // if pos = 1, insert at beginning
    {
        head = add_at_beg(head, data);
        return head;
    }

    int i = 1;
    while (i<pos && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    
    if (ptr == NULL)
    {
        printf("Position %d out of range, inserting at end.\n", pos);
        head = add_at_end(head, data);
        return head;
    }
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = ptr->prev;
    temp->data = data;
    temp->next = ptr;
    ptr->prev->next =temp ;
    ptr->prev = temp;
    
    return head;
}

struct node *del_at_pos(struct node *head, int pos)
{
    if (head == NULL)
        return NULL;

    struct node *ptr;
    ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    if (ptr->prev == NULL && ptr->next == NULL) // only one node
    {
        free(ptr);
        return NULL;
    }
    else if (ptr->next == NULL) // delete last node
    {
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else if (ptr->prev == NULL) // delete first node
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        ptr = NULL;
    }

    return head;
}

void print(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = add_to_empty(head, 10);
    head = add_at_beg(head, 20);
    head = add_at_beg(head, 30);
    head = add_at_beg(head, 40);
    head = add_at_beg(head, 50);
    head = add_at_end(head, 60);
    head = add_at_end(head, 70);
    head = add_at_end(head, 80);
    head = add_at_end(head, 90);
    head = add_at_before_pos(head, 100, 5);
    head = add_at_before_pos(head, 110, 11);

    print(head);
    head = del_at_pos(head, 11);
    print(head);

    return 0;
}