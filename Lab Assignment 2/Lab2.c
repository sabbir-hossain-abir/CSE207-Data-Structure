#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    double data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

Nodes *create()
{
    int i, n;
    double data;
    Nodes *node, *temp;

    printf("How many nodes you want to create\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter node %d data: ", i);
        scanf("%lf", &data);

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

void findByValue()
{
    Nodes *temp;
    temp = head;
    double val;
    int index = 1;

    printf("\nEnter which value you want to find\n");
    scanf("%lf", &val);

    while (temp != NULL)
    {
        if (val == temp->data)
        {
            printf("%f is in %d index\n", val, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("The List is empty\n");
}

void findByIndex()
{
    Nodes *temp;
    temp = head;
    int index, count = 1;

    printf("\nEnter which index value you want to find\n");
    scanf("%d", &index);

    while (count != index)
    {
        temp = temp->next;
        count++;
    }
    printf("%d index value is %f", index, temp->data);
}

void deleteFirst()
{
    Nodes *temp, *temp2, *node;
    temp = head;

    if (head == NULL)
    {
        return;
    }
    head = temp->next;
    free(temp);
}

void deleteLast()
{
    Nodes *temp, *temp2, *node;
    temp = head;

    if (head == NULL)
    {
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
}

void deleteAny()
{
    Nodes *temp, *temp2;
    temp = head;
    int n, i;
    printf("\nEnter which index node u want to delete\n");
    scanf("%d", &n);
    for (i = 1; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
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

int main()
{
    int option;
    int i, n;
    for (i = 1; i > n; i++)
    {
        printf("Enter 1 for Creating a list \nEnter 2 for Searching a value \nEnter 3 for Search value by index \nEnter 4 for Deleting first node \nEnter 5 for deleting last node \nEnter 6 for Deleting any node \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create();
            display();
            break;

        case 2:
            findByValue();
            display();
            break;

        case 3:
            findByIndex();
            display();
            break;

        case 4:
            deleteFirst();
            display();
            break;

        case 5:
            deleteLast();
            display();
            break;

        case 6:
            deleteAny();
            display();
            break;

        default:
            printf("Enter a valid number");
            break;
        }
    }
    return 0;
}