#include <stdio.h>
#include <stdlib.h>

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

void insert_f(int data)
{
    if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX))
    {
        printf("Circular Deque is Overflow !!");
    }
    else if (front == -1)
    {
        front = rear = 0;
        Cir_deq_arr[front] = data;
    }
    else if (front == 0)
    {
        // circular movement backward
        // front = (front == 0) ? MAX - 1 : front - 1;
        front = MAX - 1;
        Cir_deq_arr[front] = data;
    }
    else
    {
        front = front - 1;
        Cir_deq_arr[front] = data;
    }
}

void insert_r(int data)
{
    if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX))
    {
        printf("Circular Deque is Overflow !!\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    /*else{
        rear = (rear+1)%MAX;
    }*/
    Cir_deq_arr[rear] = data;
}

int delete_f()
{
    if (front == -1)
    {
        printf("Circular Deque is underflow !!");
        return -1;
    }
    int value = Cir_deq_arr[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return value;
}

int delete_r()
{
    if (front == -1)
    {
        printf("Circular Deque is underflow !!");
        return -1;
    }
    int value = Cir_deq_arr[rear];

    if (front == rear)
    {
        front = rear = -1;
    }
    // else if(front == MAX-1){
    //     front = 0;
    // }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
    return value;
}

void print()
{
    if (front == -1)
    {
        printf("Circular Deque Underflow !!\n");
        return;
    }
    int i = front;
    while (1)
    {
        printf("%d ", Cir_deq_arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        printf("1.Insert in front\n2.Insert in rear\n3.Delete in front\n4.Delete in rear\n5.Display\n6.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number for insert in the front of the Deque : ");
            int data;
            scanf("%d", &data);
            insert_f(data);
            break;
        case 2:
            printf("Enter a number for insert in the rear of the Deque : ");
            scanf("%d", &data);
            insert_r(data);
            break;
        case 3:
            printf("Deleted data at front is %d\n.", delete_f());
            break;
        case 4:
            printf("Deleted data at rear is %d\n.", delete_r());
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