#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} nodes;

nodes *head = NULL;
int size = 0;
int create()
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
    nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

void deleteIndex(int index)
{
    nodes *temp, *temp2;
    temp = head;
    int count = 1;
    if (index < 1 || index > size)
    {
        printf("\nInput correct index\n");
        return;
    }

    if (index == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        while (count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    int data;
    create();
    read();
    deleteIndex(4);
    read();
    return 0;
}