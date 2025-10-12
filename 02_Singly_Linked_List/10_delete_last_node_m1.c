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
struct node *del_at_end(struct node *head){
    if (head==NULL)
    {
        printf("List is already empty .");
        return NULL;
    }
    else if (head->link ==NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        struct node *ptr = head;
        struct node *temp = head->link;
        while (temp->link != NULL)
        {
            temp= temp->link;
            ptr = ptr->link;
        }
        
        //method 2:
        // struct node *ptr = head;
        // struct node *temp = head;
        // while (temp->link != NULL)
        // {
        //     ptr = temp;
        //     temp = temp->link;
        // }
        

        ptr->link = NULL;
        free(temp);
        temp=NULL;

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

    printf("Before delete last node :\n");
    print_data(head);
    head = del_at_end(head);//after retuning it point 1st node of the LL.
    
    printf("After delete last node :\n");
    print_data(head);

    return 0 ;
}