#include <stdio.h>
#include <stdlib.h>

typedef struct nodelist
{
    int n;
    struct nodelist *next;
}nodes;

nodes *head=NULL;

void input(){
        nodes *node,*temp;
        int n;
        scanf("%d",&n);

        while(n!=0){
            node=(nodes *)malloc(sizeof(nodes));
            node->n=n;
            node->next=NULL;
            if(head==NULL){
                head=node;
                temp=head;
            }
            else{
                temp->next=node;
                temp=temp->next;
            }
            scanf("%d",&n);
        }

}
void read(){
        nodes *temp;
        temp=head;
        if(temp==NULL){
            printf("List is empty\n");
            return;
        }
        while(temp!=NULL){
            printf("%d ",temp->n);
            temp=temp->next;
        }

}
//inserting nodes to the 1st index and last index of a node
void insert(){
    nodes *temp;
    temp=head;
    int n1,n2;
    nodes *node=(nodes *)malloc(sizeof(nodes));
    printf("Enter first node value\n");
    scanf("%d",&n1);
    node->n=n1;
    //inserting node to the 1st place
    node->next=head;
    head=node;

    //inserting node in last place
    temp=head;
    node=(nodes *)malloc(sizeof(nodes));
    printf("Enter last node value\n");
    scanf("%d",&n2);
    node->n=n2;
    //finding the last node before insertion
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=node;
    node->next=NULL;


} 


int main()
{
    int n;
    input();
    insert();
    read();


    return 0;
}