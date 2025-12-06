#include <stdio.h>


/*
Circular Deque

A linear Deque in which the last position connects back to the first position, forming a circle.
You can insert only at rear and delete only at front.

Circular Deque

A double-ended Deque arranged in circular form.
You can insert and delete from BOTH front and rear.
*/

#define MAX 5

int Cir_deq_arr[MAX];
int front = -1;
int rear = -1;

void insert_f(int data){
    if((front == 0 && rear == MAX-1)||(front ==(rear+1)%MAX)){
        printf("Circular Deque is Overflow !!");
    }
    else if(front==-1){
        front = rear = 0;
        Cir_deq_arr[front] = data;
    }
    else if(front==0){
         // circular movement backward
        // front = (front == 0) ? MAX - 1 : front - 1;
        front = MAX-1 ;
        Cir_deq_arr[front] = data;
    }
    else{
        front = front-1;
        Cir_deq_arr[front] = data;
    }
}

void insert_r(int data){
    if((front == 0 && rear ==MAX-1)||(front ==(rear+1)%MAX)){
        printf("Circular Deque is Overflow !!\n");
        return;
    }
    else if(front==-1){
        front = rear = 0;
    }
    else if(rear == MAX-1){
        rear = 0;
    }
    else{
        rear++;
    }
    /*else{
        rear = (rear+1)%MAX;
    }*/
    Cir_deq_arr[rear] = data;
}

void print(){
    if(front ==-1){
        printf("Circular Deque Underflow !!\n");
        return;
    }
    int i =front;
    while(1){
        printf("%d ",Cir_deq_arr[i]);
        if(i==rear)break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main(){

    insert_f(5); 
    insert_r(10);
    insert_r(20); 
    print();
    insert_f(15);  
    print();
    insert_f(25);
    print();

    insert_r(30);
    print();
    
    return 0;
}