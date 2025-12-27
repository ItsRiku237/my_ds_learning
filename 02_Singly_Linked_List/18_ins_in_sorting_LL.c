#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// time complexity {O(1)}
struct node *add_to_end(struct node *ptr,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link = temp;
    // ptr= ptr->link; // we return temp that reason it not mendotory to write.
    
    return temp;
}

struct node* sorting_insert(struct node* head,int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp->data = data;
    newp->link = NULL;
    int key = data;

    if(head == NULL || key < head->data ){
        newp->link = head;
        head = newp;
    }
    else{
        struct node* temp = head;
        while(temp->link != NULL && key> temp->link->data){
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}

int print_data(struct node *head){

    if (head==NULL){
    printf("Link List is empty.");
    return 0 ;
    }
    struct node *ptr = head ;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
       ptr = ptr->link;
    }

}

int main(){
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 23;
    head->link = NULL;

    struct node *ptr = head ;
    ptr = add_to_end(ptr,32);
    ptr = add_to_end(ptr,42);
    ptr = add_to_end(ptr,52);

    ptr = head;

    printf("\nBefore insertin data in sorting list : ");
    print_data(head);

    printf("\nAfter insertin data in sorting list : ");
    head = sorting_insert(head,45);
    print_data(head);

    return 0 ;
}