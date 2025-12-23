// #include <stdio.h>
// #include <stdlib.h>
// //MD = menu driven
// struct node
// {
//     int data;
//     struct node *link;
// };

// // time complexity {O(n)}
// void *add_to_end(struct node *head ,int data){
//     struct node *ptr =NULL;
//     ptr = head;
//     while (ptr->link != NULL)
//     {
//         ptr = ptr->link;
//     }
    
//     struct node *temp = (struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->link=NULL;

//     ptr->link = temp;
//     // ptr = head;
//     // return ptr; // it optional bcz inside this function, we never modify head
// }

// struct node *incert_beginning(struct node *head){
//     int data;
//     printf("Enter the element : ");
//     scanf("%d",&data);
//     struct node *temp = (struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->link=head;
//     //this head is local to the function that reason we should pass the head/temp.
//     // head = temp; //we return temp that reason i comment this line.
//     return temp;
// }

// struct node *incert_at_pos(struct node *head){
//     int data, pos;
//     printf("Enter position for insert : ");
//     scanf("%d",&pos);

//     printf("Enter the element : ");
//     scanf("%d",&data);

//     struct node *temp = (struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->link=NULL;

//     if (pos!=1)
//     {
//         struct node *ptr = head;
//         //best approch for loop
//         // int index = pos - 1;
//         // for (int i = 0; i < index-1; i++)
//         // {
//         //     ptr = ptr->link;
//         // }

//         pos--;
//         while (pos != 1)
//         {
//             ptr = ptr->link;
//             pos--;
//         }
        
        
//         temp->link = ptr->link;
//         ptr->link = temp;
//     }
//     else{
//         temp->link = head;
//         head = temp;
//     }

//     return head;
// }

// int print_data(struct node *head){

//     if (head==NULL){
//     printf("Link List is empty.");
//     return 0 ;
//     }
//     //Avoid unnecessary mallocs when just using a temporary pointer
//     struct node *ptr = head ;
//     while (ptr!=NULL)
//     {
//         printf("%d ",ptr->data);
//        ptr = ptr->link;
//     }

// }

// int main(){
//     while (1)
//     {
//         struct node *head;
//         head = (struct node*)malloc(sizeof(struct node));
//         head->data = 30;
//         head->link = NULL;

//         printf("1.Insert at begining\n2.Insert in end\n3.Incert at pos\n4.Display\n5.Exit\n");
//         int ch;
//         printf("Choose a number for operation : ");
//         scanf("%d", &ch);
//         switch (ch)
//         {
//         case 1:
//             printf("Enter a number for insert at beginning of the SLL : ");
//             int data;
//             scanf("%d", &data);
//             head = incert_beginning(head);
//             break;
//         case 2:
//             printf("Enter a number for insert at end of the SLL : ");
//             scanf("%d", &data);
//             add_to_end(head , data);
//             break;
//         case 3:
//             head = incert_at_pos(head);
//             break;
//         case 4:
//             print_data(head);
//             break;
//         case 5:
//             exit(0);
//         default:
//             printf("Enter valid number !!");
//         }
//     }

//     return 0 ;
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void add_to_end(struct node *head, int data) {
    struct node *ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
}

struct node *insert_beginning(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    return temp;
}

struct node *insert_at_pos(struct node *head, int data, int pos) {
    if (pos == 1) {
        return insert_beginning(head, data);
    }

    struct node *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Invalid position\n");
        return head;
    }

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = ptr->link;
    ptr->link = temp;

    return head;
}

void print_data(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 30;
    head->link = NULL;

    int ch, data, pos;

    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Display\n5.Exit\n");
        printf("Choose: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insert_beginning(head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            add_to_end(head, data);
            break;

        case 3:
            printf("Enter data & position: ");
            scanf("%d %d", &data, &pos);
            head = insert_at_pos(head, data, pos);
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
