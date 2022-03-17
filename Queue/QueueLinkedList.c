#include <stdio.h>
#include <stdlib.h>

typedef struct nodelist
{
    int data;
    struct nodelist *next;
} queue;

queue *head = NULL;
queue *tail = NULL;

void enQueue(int n)
{
    queue *node = (queue *)malloc(sizeof(queue));
    node->data = n;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }

    printf("%d added successfully\n", tail->data);
}

int isEmpty()
{
    return head == NULL;
}

void deQueue()
{
    if (isEmpty())
    {
        printf("Nothing to delete\n");
        return;
    }
    queue *temp;
    temp = head;
    head = head->next;
    printf("%d deleted successfully\n", temp->data);

    free(temp);
}

void display()
{
    queue *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(3);
    enQueue(6);
    deQueue();
    display();

    return 0;
}