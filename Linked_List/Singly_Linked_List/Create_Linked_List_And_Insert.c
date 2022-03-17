#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
    struct Nodelist *pre;
} Nodes;



Nodes *create()
{
    int i,n,data;
    Nodes *head=NULL,*node,*temp;

    printf("How many nodes you want to create\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter node %d data: ",i);
        scanf("%d",&data);

        node = (Nodes *)malloc(sizeof(Nodes));
        node->data = data;
        node->next = NULL;

        if(head == NULL)
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
    temp->next = head;
    return head;
}

void read(Nodes *head)
{
    Nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    do
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }while(temp!=head);
}


int main()
{

    Nodes *head = create();
    read(head);
    return 0;

}