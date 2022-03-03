#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account
{
    float amount;
    char name[30], address[30], NID[30];
};

void insert(struct account *ptr, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\n\nEnter Name, Address, NID, Amount:\n");
        scanf("%s %s %s %f", (ptr + i)->name, (ptr + i)->address, (ptr + i)->NID, &(ptr + i)->amount);
    }
}

void display(struct account *ptr, int n)
{
    printf("\n\nDisplaying Information:\n\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Name: %s\nAddress: %s\nNID: %s\nAmount: %f\n", (ptr + i)->name, (ptr + i)->address, (ptr + i)->NID, (ptr + i)->amount);
    }
}

void deleteNid(){
    
}

int main()
{
    struct account *ptr;
    int n, t;
    printf("Enter the number of records: ");
    scanf("%d", &n);
    ptr = (struct account *)malloc(n * sizeof(struct account));
    insert(ptr, n);
    display(ptr, n);

    display(ptr, n);
}