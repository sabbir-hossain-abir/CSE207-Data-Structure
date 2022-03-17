#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} stack;

stack *top = NULL;

int isEmpty()
{
    return top == NULL;
}

void push(int data)
{
    stack *node = (stack *)malloc(sizeof(stack));
    node->data = data;
    if (top == NULL)
    {
        node->next = NULL;
    }
    else
    {
        node->next = top;
    }
    top = node;
}

void pop()
{
    stack *temp;
    if (isEmpty())
    {
        printf("Nothing to delete\n");
        return;
    }
    printf("\n%d deleted from stack\n", top->data);
    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    stack *temp = top;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    pop();
    display();

    return 0;
}