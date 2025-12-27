#include<stdio.h>
#include<stdlib.h>

struct node {
    float coef;
    int expo;
    struct node* link ;
};

struct node* sort_insert(struct node* head,int coef,float exp){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp->coef = coef;
    newp->expo = exp;
    newp->link = NULL;

    if(head == NULL || exp > head->expo ){
        newp->link = head;
        head = newp;
    }
    else{
        struct node* temp = head;
        while(temp->link != NULL && exp < temp->link->expo){
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}

struct node* create_poly(struct node* head){
    struct node* newp;
    float coef;
    int exp,n;
    
    printf("Enter number of term of polynomial : ");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++){    
        printf("Enter %d term of coefficient : ",i+1);
        scanf("%f",&coef);
        printf("Enter %d term of exponetial : ",i+1);
        scanf("%d",&exp);
        head = sort_insert(head,coef,exp);
    }
    return head;
}

void print(struct node* head){
    if(head == NULL)
        printf("No Polynomial.");
    else{
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d)",temp->coef,temp->expo);
            temp = temp->link;
            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
    
}

int main(){
    struct node* head = NULL;
    head = create_poly(head);
    print(head);
    return 0;
}