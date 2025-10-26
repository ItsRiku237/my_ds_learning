#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data ;
    struct node *next;
};

struct node *add_at_end(struct node *head, int data);


struct node *add_to_empty(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;

    return head;
}

struct node *create_list(struct node *head){
    int n ,data;
    printf("Enter the no. of nodes :");
    scanf("%d",&n);
    if(n == 0)
        return head;

    printf("Enter the element for the node 1 :");
    scanf("%d",&data);
    head = add_to_empty(head,data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the element for the node %d :",i+1);
        scanf("%d",&data);
        head = add_at_end(head,data);
    }
    return head;
}

struct node *add_at_end(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
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

struct node *reverse(struct node *head){
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;
    return head;
}



int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    head = create_list(head);

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    head = reverse(head);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    
    return 0;
}