#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

void create()
{
    int i, n, data;
    Nodes *node, *temp;

    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter node %d data: ", i);
        scanf("%d", &data);

        node = (Nodes *)malloc(sizeof(Nodes));
        node->data = data;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            temp = head;
        }
        else
        {
            temp->next = node;
            temp = node;
        }
    }
}

void read()
{
    Nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

void insertFirst(int data)
{
    Nodes *node;
    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    node->next = head;
    head = node;
}

void insertLast(int data)
{
    Nodes *temp, *node;

    temp = head;

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

int main()
{
    int first, last;
    create();
    read();
    printf("\nEnter first node data\n");
    scanf("%d", &first);
    printf("\nEnter the last node\n");
    scanf("%d", &last);
    insertFirst(first);
    insertLast(last);
    read();
    return 0;
}