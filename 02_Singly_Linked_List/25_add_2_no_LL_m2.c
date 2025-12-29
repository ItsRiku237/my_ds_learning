#include <stdio.h>
#include <stdlib.h>

// Representing a n digit number in SLL.
// for add two number.
// 1. represent n digit in SLL
// 2.reverse that SLL for addition
// 3.add the no. and store the result in the resultant sLL

// add number with or without same no. of digit eg. 498+98 ,999+876
struct node
{
    int data;
    struct node *link;
};

struct node *add_node_beg(struct node *head, int n)
{
    struct node *newp = (struct node *)malloc(sizeof(struct node));
    newp->data = n;
    newp->link = head;
    head = newp;
    return head;
}

struct node *create_LL(struct node *head, int n)
{
    while (n != 0)
    {
        head = add_node_beg(head, n % 10);
        n = n / 10;
    }
    return head;
}

struct node *reverse(struct node *head)
{
    if (head == NULL || head->link == NULL)
        return head;
    struct node *next = head->link;
    struct node *current = NULL;
    head->link = NULL;
    while (next != NULL)
    {
        current = head;
        head = next;
        next = head->link;
        head->link = current;
    }
    return head;
}

struct node *add_2_no(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    int sum, carry;
    carry = 0;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        sum = 0;
        if (ptr1)
            sum += ptr1->data;
        if (ptr2)//ptr1 != NULL
            sum += ptr2->data;
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        head3 = add_node_beg(head3, sum);
        if (ptr1)
            ptr1 = ptr1->link;
        if (ptr2)
            ptr2 = ptr2->link;
    }
    if (carry)//carry != NULL
        head3 = add_node_beg(head3, carry);
    return head3;
}

void print(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("NO number.");
        return;
    }
    else
    {
        while (temp->link != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    int n1, n2;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("\nEnter 1st number : ");
    scanf("%d", &n1);
    head1 = create_LL(head1, n1);
    printf("1st number is : ");
    print(head1);
    printf("\n1st number after reverse is : ");
    head1 = reverse(head1);
    print(head1);

    printf("\nEnter 2nd number : ");
    scanf("%d", &n2);
    head2 = create_LL(head2, n2);
    printf("2nd number is : ");
    print(head2);
    printf("\n2nd number after reverse is : ");
    head2 = reverse(head2);
    print(head2);

    head3 = add_2_no(head1, head2, head3);
    printf("\nAfter addition %d and %d is : ", n1, n2);
    print(head3);
    return 0;
}