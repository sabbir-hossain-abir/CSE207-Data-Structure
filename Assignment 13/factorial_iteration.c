#include <stdio.h>

int main()
{
    long int num, count = 1, fact = 1;

    printf("Enter a number to find factorial\n");
    scanf("%d", &num);

    while (count <= num)
    {
        fact = fact * count;
        count++;
    }

    printf("Factorial of %d is %d\n", num, fact);

    return 0;
}