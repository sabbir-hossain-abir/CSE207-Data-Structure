#include <stdio.h>
#include <stdlib.h>

struct account *ptr;
int n, i;

struct account
{
    char name[100];
    char address[100];
    char nid[200];
    float amount;
};

void insert()
{

    for (i = 0; i < n; i++)
    {
        printf("Insert a name: ");
        scanf("%s \n", (ptr + i)->name);
        printf("Insert an Address: ");
        scanf("%s \n", (ptr + i)->address);
        printf("Insert a Nid: ");
        scanf("%s \n", (ptr + i)->nid);
        printf("Insert amount: ");
        scanf("%f \n", (ptr + i)->amount);
    }

    printf("%s\n %s\n %s\n %f\n", (ptr + i)->name, (ptr + i)->address, (ptr + i)->nid, (ptr + i)->amount);
}

int main()
{
    ptr = (struct account *)malloc(n * sizeof(struct account));

    // list
    printf("Enter the number of account: ");
    scanf("%d", &n);
    insert();

    // delete by NID
    /*for ( i = 0; i < n; i++)
    {
        if (nid[]==)
        {

        }

    } */

    // sorting
    /* int a[n];
     for (i = 0; i < n; i++)
     {
         ptr = &a[0];
         printf("Array element is:%d \n", *(ptr + i));
     }
     int max = a[0];
     ptr = &a[0];
     for (i = 0; i < 5; i++)
     {
         if (max < *(ptr + i))
         {
             max = *(ptr + i);
         }
     } */

    /*
    struct account a1 = {"Sabah", "Dhaka", "239243", 3443};
    insert(a1.name, a1.address, a1.nid, a1.amount); */

    return 0;
}