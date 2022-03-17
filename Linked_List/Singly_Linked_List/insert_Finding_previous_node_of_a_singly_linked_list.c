// find an index and insert its previous index
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;
int size = -1;

void create()
{
    int i, n, data;
    Nodes *node, *temp;

    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    size = n;
    for (i = 1; i <= n; i++)
    {
        node = (Nodes *)malloc(sizeof(Nodes));

        printf("\nEnter node %d data: ", i);
        scanf("%d", &data);
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
    if (head == NULL)
    {
        printf("\nLinked list empty\n");
        return;
    }
    printf("\nRead linked list data\n");

    while (temp != NULL)
    {

        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int findIndex(int data)
{
    Nodes *temp;
    int index = 1;
    temp = head;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("%d is in %d index\n", data, index);
            return index;
        }
        index++;
        temp = temp->next;
    }
    printf("No value found\n");
    return -1;
}

void insert(int index, int data)
{
    int count = 1;
    Nodes *node, *temp, *temp2;
    temp = head;
    if (index == -1)
    {
        printf("\nWrong index!\n");
        return;
    }

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    if (index == 1)
    {
        node->next = head;
        head = node;
    }
    else
    {
        while (count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        // traversing to the previous node
        node->next = temp->next;
        temp->next = node;
    }
}

int main()
{
    int data, index, newdata;
    create();
    printf("\nEnter the data you want to find\n");
    scanf("%d", &data);
    index = findIndex(data);
    if (index == -1)
        return 0;
    // insert node
    printf("\nEnter new node data\n");
    scanf("%d", &newdata);
    insert(index, newdata);
    printf("Final:\n");
    read();
    return 0;
}