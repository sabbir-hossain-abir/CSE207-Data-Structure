#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, *p, temp = 0, k;
    printf("Input size of array: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (*(p + i) < 0)
            {
                temp++;
                for (j = i; j < n; j++)
                {
                    *(p + j) = *(p + j + 1);
                }
            }
        }
    }
    printf("Array elements after deletion: ");

    for (i = 0; i < n - temp; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}