#include <stdio.h>
#define MAX 100

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue_arr[rear] = data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", cqueue_arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

int peek()
{
    if (front == -1)
    {
        printf("\nQueue Underflow\n");
    }
    return cqueue_arr[front];
}

void display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d\n", cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main()
{
    int option, data;
    do
    {
        printf("\n-----Main Menu-----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Quit\n");

        printf("Enter your Choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &data);

            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\nElement at the front is  : %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n----EXIT POINT----\n");
            break;
        default:
            printf("Enter the valid option(1/2/3/4/5)\n");
        }
    } while (option != 5);

    return 0;
}