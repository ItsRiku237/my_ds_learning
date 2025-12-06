#include <stdio.h>

#define MAX 5

int cir_que_arr[MAX];
int front = -1;
int rear = -1;

void insert(int data){
    if(front ==(rear+1)%MAX){
        printf("Circular Queue is Overflow !!");
    }
    else if(front==-1){
        front++;
        rear++;
        cir_que_arr[front] = data;
    }
    else{
        rear = (rear +1)%MAX;
        cir_que_arr[rear] = data;
    }
}

int delete(){
    if(front ==-1){
        printf("Circular Queue Underflow !!");
    }
    else if(front == rear){
        int value =cir_que_arr[front];
        front = -1;
        rear = -1;
        return value;
    }
    else
    {
        int value =cir_que_arr[front];
        front++;
        return value;
    }
}

void print(){
    if(front ==-1){
        printf("Circular Queue Underflow !!\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",cir_que_arr[i]);
    }
    printf("\n");
}

int main(){

    insert(10); 
    insert(15); 
    insert(20); 

    print();

    delete(); 
    
    print();

    insert(25); 
    insert(30);

    print();

    delete(); 

    print();

    return 0;
}