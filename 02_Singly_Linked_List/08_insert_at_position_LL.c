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

// time complexity {O(n)}
struct node *incert_at_pos(struct node *head){
    int data, pos;
    printf("Enter position for insert : ");
    scanf("%d",&pos);

    printf("Enter the element : ");
    scanf("%d",&data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    if (pos!=1)
    {
        struct node *ptr = head;
        //best approch for loop
        // int index = pos - 1;
        // for (int i = 0; i < index-1; i++)
        // {
        //     ptr = ptr->link;
        // }

        pos--;
        while (pos != 1)
        {
            ptr = ptr->link;
            pos--;
        }
        
        
        temp->link = ptr->link;
        ptr->link = temp;
    }
    else{
        temp->link = head;
        head = temp;
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

    
    head = incert_at_pos(head);//after retuning it point 1st node of the LL.
    
    print_data(head);

    return 0 ;
}