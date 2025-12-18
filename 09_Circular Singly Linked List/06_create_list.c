#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* add_to_empty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    temp->data = data;
    temp->next = temp;
    return temp;
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

struct node* create_list(struct node* tail ){
    int i, n, data;
    printf("Enter thr number of the linked list : ");
    scanf("%d",&n);
    if(n == 0 )
        return tail;

    printf("Enter the element 1 : ");
    scanf("%d",&data);
    tail = add_to_empty(data);
    
    for (int i = 1; i < n; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&data);
        tail = add_at_end(tail,data);
    }
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
    tail = create_list(tail);
    print(tail);
    return 0;
}