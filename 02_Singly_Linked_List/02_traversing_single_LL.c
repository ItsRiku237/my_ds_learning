#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int count_node(struct node *head){
    int count = 0;
    if (head==0){
    printf("Link List is empty.");
    return 0;
    }
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr = head ;
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    

    // while (head !=NULL)
    // {
    //     count +=1;
    //     head = head->link;
    // }
    //when head pointer travers then we can not acces 1st element
    // and also below line of code not work.
    // printf("%d %d\n",head->data,head->link->data);
    return count;
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

    printf("%d %d\n",head->data,head->link->data);
    // printf("%d %d\n",head->data,current->data);//same as upper line.

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 42;
    current->link = NULL;

    head->link->link = current;

    int count;
    count = count_node(head);
    printf("No. of nodes present is %d.",count);

    return 0 ;
}