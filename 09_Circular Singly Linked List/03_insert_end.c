#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* add_to_empty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node* add_at_beg(struct node* tail, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    return tail;
}

struct node* add_at_end(struct node* tail, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = tail->next;
    return tail;
}

void print(struct node* tail){
    struct node* p = tail->next;
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=tail->next);
}

int main(){
    struct node* tail ;
    tail = add_to_empty(10);
    tail = add_at_beg(tail ,20);
    tail = add_at_beg(tail ,30);
    tail = add_at_end(tail ,40);
    tail = add_at_end(tail ,50);
    print(tail);
    return 0;
}