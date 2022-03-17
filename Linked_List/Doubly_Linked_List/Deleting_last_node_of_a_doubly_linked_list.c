#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{

    int a;
    struct Nodelist *pre;
    struct Nodelist *next;
} nodes;

nodes *head = NULL;

void input()
{
    nodes *temp, *node;
    int i, n, num;
    printf("How many nodes you want to insert\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter %d node: ", i);
        scanf("%d", &num);
        // allocating memory
        node = (nodes *)malloc(sizeof(nodes));
        node->a = num;
        node->pre = NULL;
        node->next = NULL;
        // inserting first node address to head
        if (head == NULL)
        {
            head = node;
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

    while (temp != NULL)
    {
        printf("%d ", temp->a);
        temp = temp->next;
    }
}

void deleteLastNode()
{
    nodes *temp, *temp2;
    // if there is not any node
    if (head != NULL)
    {
        temp = head;
    }
    // deleting last node of a doubly linked list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->pre;
    temp2->next = NULL;
    free(temp);
}

int main()
{
    input();
    printf("Nodelist before deleting any nodes\n");
    read();
    deleteLastNode();
    printf("\nNodelist after deleting last node\n");
    read();

    return 0;
}
