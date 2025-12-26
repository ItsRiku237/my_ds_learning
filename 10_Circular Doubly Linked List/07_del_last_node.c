#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

/* Create first node */
struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

/* Insert at beginning */
struct node *ins_at_beg(struct node *tail)
{
    int data;
    printf("Enter data for insert at beginning: ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    if (tail == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    struct node *first = tail->next;

    temp->next = first;
    temp->prev = tail;
    first->prev = temp;
    tail->next = temp;

    return tail; // tail does NOT change
}

/* Insert at end */
struct node *ins_at_end(struct node *tail)
{
    int data;
    printf("Enter data for insert at end : ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    if (tail == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    struct node *first = tail->next;

    first->prev = temp;
    temp->next = first;
    temp->prev = tail;
    tail->next = temp;

    tail = temp;

    return tail; // tail change
}

/* Insert after position */
struct node *ins_aft_pos(struct node *tail)
{
    int data, pos;
    printf("Enter position for insert after : ");
    scanf("%d", &pos);

    if (tail == NULL)
    {
        printf("List is empty so enter data is 1st node. ");
        printf("Enter data for insert after position : ");
        scanf("%d", &data);
        return create_node(data);
    }

    struct node *first = tail->next;

    if (pos == 1)
    {
        return ins_at_beg(tail);
    }
    else
    {
        struct node *start = tail->next;
        int n = 1;
        while (1 != pos)
        {
            start = start->next;
            if (start == tail)
                return ins_at_end(tail);
            pos--;
        }
        printf("Enter data for insert after position : ");
        scanf("%d", &data);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = start->next;
        temp->prev = start;
        start->next->prev = temp;
        start->next = temp;
    }
    return tail; // tail does not change
}

/* Insert before position */
struct node *ins_bef_pos(struct node *tail)
{
    int data, pos;
    printf("Enter position for insert before : ");
    scanf("%d", &pos);

    if (tail == NULL)
    {
        printf("List is empty so enter data is 1st node. ");
        printf("Enter data : ");
        scanf("%d", &data);
        return create_node(data);
    }

    struct node *first = tail->next;

    if (pos == 1)
    {
        return ins_at_beg(tail);
    }
    else
    {
        struct node *start = tail->next;
        while (1 != pos)
        {
            start = start->next;
            pos--;
        }
        printf("Enter data for insert before position : ");
        scanf("%d", &data);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = start;
        temp->prev = start->prev;
        start->prev->next = temp;
        start->prev = temp;
    }
    return tail; // tail does not change
}

/* del first node */
struct node *del_first_node(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty . ");
        return tail;
    }

    printf("First node is Deleted : ");
    struct node *first = tail->next;
    tail->next = first->next;
    first->next->prev =tail;
    free(first);
    first = NULL;

    return tail; // tail does not change
}

/* del last node */
struct node *del_last_node(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty . ");
        return tail;
    }

    printf("Last node is Deleted : ");
    struct node *temp = tail;
    tail = tail->prev;
    tail->next = temp->next;
    temp->next->prev = tail;

    free(temp);
    temp = NULL;

    return tail; // tail does not change
}

/* Print list */
void print(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *p = tail->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

int main()
{
    struct node *tail = NULL;

    tail = create_node(10);
    print(tail);

    tail = ins_at_beg(tail);
    print(tail);

    tail = ins_at_end(tail);
    print(tail);

    tail = ins_aft_pos(tail);
    print(tail);

    tail = ins_bef_pos(tail);
    print(tail);

    tail = del_first_node(tail);
    print(tail);

    tail = del_last_node(tail);
    print(tail);

    return 0;
}
