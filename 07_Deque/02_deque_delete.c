#include <stdio.h>

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

    insert_f(5); 
    insert_r(20); 
    print();
    insert_r(15);  
    print();
    delete_f();
    print();
    insert_r(30);
    insert_f(10); 
    print();
    insert_f(25);
    print();


    return 0;
}