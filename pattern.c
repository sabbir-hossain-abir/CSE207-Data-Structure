#include <stdio.h>
#include <conio.h>
int main()
{
    int n, s, x, y;
    printf("Enter number");
    scanf("%d", &n);
    for (x = 1; x <= n; x++)
    {
        for (s = x; s < n; s++)
            printf(" ");

        for (y = 1; y <= x; y++)
            printf("* ");
        printf("\n");
    }
    return 0;
}