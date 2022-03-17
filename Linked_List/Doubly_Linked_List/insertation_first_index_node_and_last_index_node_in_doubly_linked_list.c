#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
    struct Nodelist *pre;
} nodes;

nodes *head = NULL;

nodes create()
{
    int i, n, data;
    nodes *node, *temp;
    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter node %d data: ", i);
        scanf("%d", &data);

        node = (nodes *)malloc(sizeof(nodes));
        node->data = data;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            head->pre = NULL;
            temp = head;
        }
        else
        {
            temp->next = node;
            node->pre = temp;
            temp = node;
        }
    }
}

void read()
{
    nodes *temp;
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
    nodes *node, *temp;
    temp = head;
    node = (nodes *)malloc(sizeof(nodes));
    node->data = data;

    node->pre = NULL;
    node->next = temp;
    temp->pre = node;
    head = node;
}

void insertLast(int data)
{
    nodes *node, *temp;

    temp = head;
    node = (nodes *)malloc(sizeof(nodes));
    node->data = data;
    node->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->pre = temp;
}

int main()
{
    int data;
    create();
    read();
    insertFirst(8);
    insertLast(11);
    read();
    return 0;
}
