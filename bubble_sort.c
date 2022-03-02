#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int size = 9;
    int swap=*(p+0);
    p = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter your values: ");
        scanf("%d", p + i);
    }
    printf("This is the output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", *(p + i));
        if (swap < *(p + i))
        {
            swap = &*(p + i);
        }

        printf(" %d", swap);
    }
}