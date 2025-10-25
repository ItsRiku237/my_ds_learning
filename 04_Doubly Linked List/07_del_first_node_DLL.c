#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data ;
    struct node *next;
};

struct node *add_to_empty(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;

    return head;
}

struct node *add_at_beg(struct node *head,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    
    return temp;
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

struct node *add_at_before_pos(struct node *head,int data,int pos){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr;
    struct node *ptr2;
    ptr = head;
    if (pos == 1)
    {
        head = add_at_beg(head,data);
        return head;
    }
    else{
        while ((pos-1) != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        ptr2 = ptr->next;
        temp->next =ptr2;
        ptr->next = temp;
        temp->prev = ptr;
        ptr2->prev = temp;
        return head;
    }
}

struct node *del_first_node(struct node *head){
    //method 1 :
    // struct node *ptr = head;
    // head= ptr->next;
    // free(ptr);
    // ptr = NULL;

    // method 2 :
    head = head->next;
    free(head->prev);
    head->prev = NULL;

    return head ;
}

void print(struct node *head){
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = add_to_empty(head,10);
    head = add_at_beg(head,20);
    head = add_at_beg(head,30);
    head = add_at_beg(head,40);
    head = add_at_beg(head,50);
    head = add_at_end(head,60);
    head = add_at_end(head,70);
    head = add_at_end(head,80);
    head = add_at_end(head,90);
    head = add_at_before_pos(head,100,5);
    head = add_at_before_pos(head,110,10);

    print(head);
    head = del_first_node(head);
    print(head);

    return 0;
}