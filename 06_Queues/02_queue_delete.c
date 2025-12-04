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
    insert(5); 
    insert(10); 
    insert(15); 
    insert(20); 
    insert(25); 
    // insert(30);
    print();
    delete(); 
    print();
    return 0;
}