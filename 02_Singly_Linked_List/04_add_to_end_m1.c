#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// time complexity {O(n)}
void *add_to_end(struct node *head ,int data){
    struct node *ptr =NULL;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link = temp;
    // ptr = head;
    // return ptr; // it optional bcz inside this function, we never modify head
}

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

    add_to_end(head,32);
    add_to_end(head,42);
    add_to_end(head,52);

    print_data(head);

    return 0 ;
}