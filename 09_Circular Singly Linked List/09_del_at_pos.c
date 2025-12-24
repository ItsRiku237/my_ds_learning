#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Create a circular list with one node */
struct node* add_to_empty(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = temp;
    return temp;
}

/* Insert node at end */
struct node* add_at_end(struct node *tail, int data) {
    if (tail == NULL)
        return add_to_empty(data);

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    return new_node;   // new node becomes new tail
}

/* Create list */
struct node* create_list(struct node *tail) {
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
        return NULL;

    printf("Enter element 1: ");
    scanf("%d", &data);
    tail = add_to_empty(data);

    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }
    return tail;
}

/* Delete first node */
void delete_first_node(struct node **tail) {
    if (*tail == NULL)
        return;

    struct node *temp = (*tail)->next;

    if (temp == *tail) {   // only one node
        free(temp);
        *tail = NULL;
        return;
    }

    (*tail)->next = temp->next;
    free(temp);
}

/* Delete last node */
void delete_last_node(struct node **tail) {
    if (*tail == NULL)
        return;

    if ((*tail)->next == *tail) {  // only one node
        free(*tail);
        *tail = NULL;
        return;
    }

    struct node *p = (*tail)->next;

    while (p->next != *tail) {
        p = p->next;
    }

    p->next = (*tail)->next;
    free(*tail);
    *tail = p;
}

/* Delete node at given position */
void delete_at_position(struct node **tail) {
    if (*tail == NULL) {
        printf("List is empty\n");
        return;
    }

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        delete_first_node(tail);
        return;
    }

    struct node *p = (*tail)->next;

    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
        if (p == *tail) {
            printf("Invalid position\n");
            return;
        }
    }

    struct node *temp = p->next;
    p->next = temp->next;

    if (temp == *tail)
        *tail = p;

    free(temp);
}

/* Display list */
void print_list(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

/* Main function */
int main() {
    struct node *tail = NULL;

    tail = create_list(tail);

    printf("\nInitial list: ");
    print_list(tail);

    delete_last_node(&tail);
    printf("After deleting last node: ");
    print_list(tail);

    delete_at_position(&tail);
    printf("After deleting at position: ");
    print_list(tail);

    return 0;
}
