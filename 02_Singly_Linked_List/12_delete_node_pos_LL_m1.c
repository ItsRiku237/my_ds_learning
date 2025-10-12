#include <stdio.h>
#include <stdlib.h>

//updating head (in main) with the value returned from the function.
//without send add of head .
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
struct node *del_at_pos(struct node *head){
    int pos;
    printf("Enter position for delete : ");
    scanf("%d",&pos);
    
    struct node *previous = head;
    struct node *current = head;

    if (head==NULL)
    {
        printf("List is already empty .");
        return NULL;
    }
    else if (pos == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
        return head;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->link;
            pos = pos-1;
        }
        //it also work
        // for (int i = 0; i < pos-2; i++)
        // {
        //     ptr = ptr->link;
        // }

        previous->link = current->link;
        free(current);
        current = NULL;

        return head;
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
    head = del_at_pos(head);//after retuning it point 1st node of the LL.
    
    printf("After delete the node :\n");
    print_data(head);

    return 0 ;
}