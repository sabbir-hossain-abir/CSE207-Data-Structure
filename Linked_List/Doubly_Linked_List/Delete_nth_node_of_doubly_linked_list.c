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
        // doubly linked list last node
        last = temp;
    }
}

void read()
{
    nodes *temp, *temp2;
    temp = head;
    printf("\nRead linked list data");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp2 = temp;
        temp = temp->next;
    }
}

void deleteIndex(int n)
{
    nodes *temp, *temp2;
    int count = 1;
    temp = head;
    if (head == NULL)
    {
        printf("\nNothing to delete\n");
        return;
    }
    // delete first node
    if (n == 1)
    {
        head = head->next;
        head->pre = NULL;
        free(temp);
    }
    else
    {
        // traversing to any particular node
        while (count < n - 1)
        {
            temp = temp->next;
            count++;
        }
        // delete last node
        if (last == temp->next)
        {
            temp->next = NULL;
            free(last);
            return;
        }
        // delete any particular node
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->pre = temp;
        free(temp2);
    }
}

int main()
{
    int data, index;
    create();
    read();
    printf("\nEnter the index\n");
    scanf("%d", &index);
    deleteIndex(index);
    read();
    return 0;
}
