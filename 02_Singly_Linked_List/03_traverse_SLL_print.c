#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int print_data(struct node *head){

    if (head==NULL){
    printf("Link List is empty.");
    return 0 ;
    }
    //Avoid unnecessary mallocs when just using a temporary pointer
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

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 32;
    current->link = NULL;
    head->link = current;
    
    current = (struct node*)malloc(sizeof(struct node));
    current->data = 42;
    current->link = NULL;
    head->link->link = current;

    print_data(head);

    return 0 ;
}