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
nodes *last = NULL;
int size = -1;

void create()
{
    int i, n, data;
    nodes *node, *temp;
    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    size = n;
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
    last = temp;
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

void insertIndex(int data, int index)
{
    nodes *node, *temp, *temp2;
    temp = head;
    int count = 1;
    node = (nodes *)malloc(sizeof(nodes));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;

    if (index == 1)
    {
        node->pre = NULL;
        node->next = temp;
        temp->pre = node;
        head = node;
    }
    else if (index == size + 1)
    {
        last->next = node;
        node->pre = last;
    }
    else
    {

        while (count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        temp2 = temp->next;
        node->next = temp2;
        temp2->pre = node;
        node->pre = temp;
        temp->next = node;
    }
}

int main()
{
    int data;
    create();
    read();
    insertIndex(15, 5);
    read();
    return 0;
}
