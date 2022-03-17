#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stackarray
{
    int *arr;
    int capacity;
    int top;
} stack;

stack *node = NULL;
// create stack with array
void create(int n)
{
    node = (stack *)malloc(sizeof(stack));
    node->arr = (int *)malloc(sizeof(int) * n);
    node->top = -1;
    node->capacity = n;
}
// check empty stack
int emptyIf()
{
    return node->top == -1;
}
// check full stack
int fullIf()
{
    return node->top == node->capacity - 1;
}
// push value into the stack
void push(int val)
{
    if (fullIf())
    {
        printf("stack is full\n");
        return;
    }
    node->arr[++node->top] = val;
}
// Pop value out from the stack
void pop()
{
    if (emptyIf())
    {
        printf("nothing to pop out\n");
        return;
    }
    node->top--;
}
// display top element of the stack
int peep()
{
    return node->arr[node->top];
}
int main()
{
    int a;
    printf("Enter array size\n");
    scanf("%d", &a);
    create(a);
    push(2);
    push(3);
    // push(4);
    // pop();
    printf("Top element is %d", peep());
    return 0;
}