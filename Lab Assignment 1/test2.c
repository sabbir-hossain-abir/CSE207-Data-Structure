#include <stdio.h>
#include <stdlib.h>
struct account
{
    float amount;
    char name[30], address[30], NID[30];
};

int main()
{
    struct account *ptr;
    int n, t;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    ptr = (struct account *)malloc(n * sizeof(struct account));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Name: ");
        scanf("%s\n", (ptr + i)->name);
        printf("Enter Address: ");
        scanf("%s\n", (ptr + i)->address);
        printf("Enter NID: ");
        scanf("%s\n", (ptr + i)->NID);
        printf("Enter Amount: ");
        scanf("%f\n", &(ptr + i)->amount);
    }

    printf("Displaying Information:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Name: %s\n Address: %s\n NID: %s\n Amount: %f\n", (ptr + i)->name, (ptr + i)->address, (ptr + i)->NID, (ptr + i)->amount);
    }
}