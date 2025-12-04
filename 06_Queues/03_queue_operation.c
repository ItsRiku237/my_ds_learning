#include <stdio.h>

#define MAX 5
int queue_arr[MAX];
int front = -1;
int rear = -1;

void insert(int data){
    if(rear == MAX-1){
        printf("Stack is Overflow !!");
    }
    else if(front==-1 && rear == -1){
        front++;
        rear++;
        queue_arr[rear] = data;
    }
    else{
        rear++;
        queue_arr[rear] = data;
    }
}

int delete(){
    if((rear == -1 && front ==-1 )||(rear<front)){
        printf("Stack Underflow !!");
    }
    else
    {
        int value =queue_arr[front];
        front++;
        return value;
    }
}

void print(){
    if((rear == -1 && front ==-1 )||(rear<front)){
        printf("Stack Underflow !!");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue_arr[i]);
    }
    printf("\n");
}

int main(){
    while (1){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter a number for insert in the Stack : ");
                int data;
                scanf("%d",&data);
                insert(data); 
                break;
            case 2:
                printf("Deleted data is %d\n.",delete());
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid number !!");
            }
    }
    return 0;
}