#include <stdio.h>
#include <stdlib.h>

//inside the function, you can modify the actual head in main using *head.
//without returning head.
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

// time complexity {O(n)}
// You don’t want to return anything (void function)
// Then you must pass the address of the head pointer:
void del_at_pos(struct node **head){
    int pos;
    printf("Enter position for delete : ");
    scanf("%d",&pos);
    
    struct node *previous = *head;
    struct node *current = *head;

    if (*head==NULL)
    {
        printf("List is already empty .");

    }
    else if (pos == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->link;
            pos = pos-1;
        }

        previous->link = current->link;
        free(current);
        current = NULL;

    }

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
    printf("\n");
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

    printf("Before delete the node :\n");
    print_data(head);

    del_at_pos(&head);
    
    printf("After delete the node :\n");
    print_data(head);

    return 0 ;
}