#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque_arr[MAX];

int front = -1;
int rear = -1;

void insert_f(int data){
    if(front == 0){
        printf("Deque is Overflow !!");
    }
    else if(front==-1 && rear == -1){
        front++;
        rear++;
        deque_arr[front] = data;
    }
    else{
        front--;
        deque_arr[front] = data;
    }
}
void insert_r(int data){
    if(rear == MAX-1){
        printf("Deque is Overflow !!");
    }
    else if(front==-1 && rear == -1){
        front++;
        rear++;
        deque_arr[rear] = data;
    }
    else{
        rear++;
        deque_arr[rear] = data;
    }
}

int delete_f(){
    if((rear == -1 && front ==-1 )||(rear<front)){
        printf("Deque Underflow !!");
    }
    else
    {
        int value =deque_arr[front];
        front++;
        return value;
    }
}
int delete_r(){
    if((rear == -1 && front == -1 )||(rear<front)){
        printf("Deque Underflow !!\n");
    }
    else
    {
        int value =deque_arr[rear];
        rear--;
        return value;
    }
}

void print(){
    if((rear == -1 && front ==-1 )||(rear<front)){
        printf("Deque Underflow !!\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",deque_arr[i]);
    }
    printf("\n");
}

int main(){
    while (1){
            printf("1.Insert in front\n2.Insert in rear\n3.Delete in front\n4.Delete in rear\n5.Display\n6.Exit\n");
            int ch;
            printf("Choose a number for operation : ");
            scanf("%d",&ch);
            switch (ch){
                case 1:
                    printf("Enter a number for insert in the front of the Deque : ");
                    int data;
                    scanf("%d",&data);
                    insert_f(data); 
                    break;
                case 2:
                    printf("Enter a number for insert in the rear of the Deque : ");
                    scanf("%d",&data);
                    insert_r(data); 
                    break;
                case 3:
                    printf("Deleted data at front is %d\n.",delete_f());
                    break;
                case 4:
                    printf("Deleted data at rear is %d\n.",delete_r());
                    break;
                case 5:
                    print();
                    break;
                case 6:
                    exit(0);
                default:
                    printf("Enter valid number !!");
                }
        }
    return 0;
}