#include <stdio.h>
#include <stdlib.h>

//Representing a n digit number in SLL.
//for add two number.

struct node
{
    int data;
    struct node* link;
};

struct node* add_node_beg(struct node* head,int n){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp->data = n;
    newp->link = head;
    head = newp;
    return head;
}

struct node* create_LL(struct node* head , int n){
    while (n != 0)
    {
        head = add_node_beg(head, n%10);
        n = n/10;
    }
    return head;
}

void print(struct node* head){
    struct node* temp = head;
    if(head == NULL){
        printf("NO number.");
        return;
    }
    else{
        while (temp->link != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->link;
        }
        printf("%d",temp->data);
    }
}

int main(){
    int n1,n2;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("\nEnter 1st number : ");
    scanf("%d",&n1);
    head1 = create_LL(head1,n1);
    printf("1st number is : ");
    print(head1);
    
    printf("\nEnter 2nd number : ");
    scanf("%d",&n2);
    head2 = create_LL(head2,n2);
    printf("2nd number is : ");
    print(head2);
    return 0;
}