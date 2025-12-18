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
    if (tail == NULL)
        return add_to_empty(data);
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = tail->next;
    // tail = new_node;

    return tail;
}

struct node* add_aft_pos(struct node* tail , int data, int pos){
    if (tail == NULL || pos <= 0) {
        printf("Invalid position\n");
        return tail;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    struct node* p = tail->next;
    int i=1;

    // while (pos> 1)
    // {
    //     p = p->next ;
    //     pos--;
    // }

    while (i<=pos-1)
    {
        p = p->next;
        if (p == tail->next) {
            printf("Position out of range\n");
            return tail;
        }
        i++;
    }

    // if( p = tail){
    //     return add_at_end(tail,data);
    // }
    new_node->next = p->next;
    p->next = new_node;

    if (p == tail)
        tail = new_node;

    return tail;

    // if (p->next == tail->next)
    // {
    //     return add_at_end(tail,data);
    // }
    // else{
    //     new_node->next = p->next;
    //     p->next = new_node;
    //     return tail;
    // }

}

struct node* add_bef_pos(struct node* tail , int data, int pos){
    if (tail == NULL || pos <= 0) {
        printf("Invalid position\n");
        return tail;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    if (pos==1)
    {
        return add_at_beg(tail,data);
    }
    
    struct node* p = tail->next;
    int i=1;

    // while (i < pos - 1)//same as below
    while (i<=pos-2)
    {
        p = p->next;
        if (p == tail->next) {
            printf("Position out of range\n");
            return tail;
        }
        i++;
    }
    
    new_node->next = p->next;
    p->next = new_node;
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
    tail = add_aft_pos(tail ,50,3);
    tail = add_bef_pos(tail ,90,1);
    tail = add_aft_pos(tail ,450,7);
    print(tail);
    return 0;

}
