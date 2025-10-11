#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main(){
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));

    head->data = 23;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));

    current->data = 32;
    current->link = NULL;
    head->link = current;

    printf("%d %d",head->data,head->link->data);
    // printf("%d %d",head->data,current->data);//same as upper line.

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 42;
    current->link = NULL;

    head->link->link = current;

    /* method 2 
    struct node *current2 = (struct node*)malloc(sizeof(struct node));

    current2->data = 32;
    current2->link = NULL;
    current->link = current2; */

    return 0 ;
}
