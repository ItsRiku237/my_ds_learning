#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

/* Create first node */
struct node* create_node(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

/* Insert at beginning */
struct node* ins_at_beg(struct node* tail) {
    int data;
    printf("Enter data for insert at beginning: ");
    scanf("%d", &data);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (tail == NULL) {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    struct node* first = tail->next;

    temp->next = first;
    temp->prev = tail;
    first->prev = temp;
    tail->next = temp;

    return tail;   // tail does NOT change
}

/* Insert at end */
struct node* ins_at_end(struct node* tail) {
    int data;
    printf("Enter data for insert at end : ");
    scanf("%d", &data);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (tail == NULL) {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    struct node* first = tail->next;

    first->prev = temp;
    temp->next = first;
    temp->prev = tail;
    tail->next = temp;

    tail = temp;

    return tail;   // tail change
}

/* Print list */
void print(struct node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

int main() {
    struct node* tail = NULL;

    tail = create_node(10);
    print(tail);

    tail = ins_at_beg(tail);
    print(tail);

    tail = ins_at_end(tail);
    print(tail);

    return 0;
}
