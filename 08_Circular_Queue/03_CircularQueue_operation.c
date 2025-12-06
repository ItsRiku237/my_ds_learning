#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/*
Circular Queue

A linear queue in which the last position connects back to the first position, forming a circle.
You can insert only at rear and delete only at front.

Circular Deque

A double-ended queue arranged in circular form.
You can insert and delete from BOTH front and rear.
*/

int cir_que_arr[MAX];
int front = -1;
int rear = -1;

void insert(int data)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Circular Queue is Overflow !!");
    }
    else if (front == -1)
    {
        front++;
        rear++;
        cir_que_arr[front] = data;
    }
    else
    {
        rear = (rear + 1) % MAX;
        cir_que_arr[rear] = data;
    }
}

int delete()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow !!\n");
    }
    else if (front == rear)
    {
        int value = cir_que_arr[front];
        front = -1;
        rear = -1;
        return value;
    }
    else
    {
        int value = cir_que_arr[front];
        front++;
        return value;
    }
}

void print()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow !!\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", cir_que_arr[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        int ch;
        printf("Choose a number for operation : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number for insert in the Stack : ");
            int data;
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Deleted data is %d\n.", delete());
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