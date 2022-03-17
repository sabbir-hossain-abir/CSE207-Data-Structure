#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

Nodes create()
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

void delFirst()
{
    Nodes *temp;

    if (head == NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void delLast()
{
    Nodes *temp, *temp2;
    temp = head;

    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
}

int main()
{

    create();
    read();
    delFirst();
    delLast();
    read();
    return 0;
}