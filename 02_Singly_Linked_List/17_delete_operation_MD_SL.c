#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *del_at_beginning(struct node *head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

struct node *del_at_end(struct node *head) {
    if (head == NULL) {
        printf("List is already empty\n");
        return NULL;
    }
    if (head->link == NULL) {
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    struct node *temp = head->link;

    while (temp->link != NULL) {
        ptr = temp;
        temp = temp->link;
    }

    ptr->link = NULL;
    free(temp);
    return head;
}

struct node *del_at_pos(struct node *head) {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is already empty\n");
        return NULL;
    }

    if (pos == 1) {
        return del_at_beginning(head);
    }

    struct node *prev = head;
    struct node *curr = head->link;

    for (int i = 2; i < pos; i++) {
        if (curr == NULL) {
            printf("Invalid position\n");
            return head;
        }
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("Invalid position\n");
        return head;
    }

    prev->link = curr->link;
    free(curr);
    return head;
}

void print_data(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int ch;

    while (1) {
        printf("\n1.Delete at beginning\n2.Delete at end\n3.Delete at position\n4.Display\n5.Exit\n");
        printf("Choose: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            head = del_at_beginning(head);
            break;
        case 2:
            head = del_at_end(head);
            break;
        case 3:
            head = del_at_pos(head);
            break;
        case 4:
            print_data(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
