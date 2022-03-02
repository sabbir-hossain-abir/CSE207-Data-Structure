#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    float data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

Nodes *create()
{
    int i, n;
    float data;
    Nodes *node, *temp;

    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter node %d data: ", i);
        scanf("%f", &data);

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

void display()
{
    Nodes *temp;
    temp = head;
    printf("\nDisplaying linked list data \n");
    while (temp != NULL)
    {
        printf(" %f \n", temp->data);
        temp = temp->next;
    }
}

void insertFirst()
{
    Nodes *temp;
    temp = head;
    float n1, n2;
    Nodes *node = (Nodes *)malloc(sizeof(Nodes));
    printf("Enter first node value\n");
    scanf("%f", &n1);
    node->data = n1;
    // inserting node to the 1st place
    node->next = head;
    head = node;
}

void insertLast()
{
    Nodes *temp;
    float n1, n2;
    temp = head;
    Nodes *node = (Nodes *)malloc(sizeof(Nodes));

    // inserting node in last place
    temp = head;
    node = (Nodes *)malloc(sizeof(Nodes));
    printf("Enter last node value\n");
    scanf("%f", &n2);
    node->data = n2;
    // finding the last node before insertion
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}

void insertAnywhere()
{
    int n, count = 1;
    float data;
    Nodes *temp,
        *node;
    temp = head;
    printf("\nInsert index where you want to insert node\n");
    scanf("%d", &n);
    printf("Enter the data\n");
    scanf("%f", &data);

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    if (n == 1)
    {
        node->next = head;
        head = node;
    }
    else
    {
        while (count < n - 1)
        {
            temp = temp->next;
            count++;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

int main()
{
    int option;

    create();
    display();

    printf("Enter 1 for Inserting in first node \nEnter 2 for Inserting in last node \nEnter 3 for Inserting an node Anywhere\n ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        insertFirst();
        display();
        break;

    case 2:
        insertLast();
        display();
        break;

    case 3:
        insertAnywhere();
        display();
        break;

    default:
        printf("Enter a valid number");
        break;
    }

    return 0;
}