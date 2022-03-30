#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *current = head; // current node set to head

    printf("traversing the list\n");
    while (current != NULL)
    { // traverse until current node isn't NULL
        printf("%d ", current->data);
        current = current->next; // go to next node
    }
}

void reverse_display(struct node *head)
{
    if (head)
    {
        // recursive call to display in reverse order
        reverse_display(head->next);
        printf("%d ", head->data);
    }
}

struct node *creatnode(int d)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

int main()
{
    int x, n;

    printf("Enter 0 to exit the list\n");
    printf("Enter values\n");

    struct node *curr, *temp;

    scanf("%d", &n);
    struct node *head = creatnode(n);

    temp = head;

    for (x = 1; x < n; x++)
    {
        curr = creatnode(n);
        temp->next = curr;
        temp = temp->next;
        scanf("%d", &n);
    }

    display(head);
    printf("\ndisplaying in reverse order\n");
    reverse_display(head);

    return 0;
}
