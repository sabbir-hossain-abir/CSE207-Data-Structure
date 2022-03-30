#include <stdio.h>

int fact(int num)
{
    if (num == 0)
    {
        return 1;
    }

    else
        return (num * fact(num - 1));
}

int main()
{
    int num;

    printf("Enter an integer number to find its Factorial\n");
    scanf("%d", &num);

    printf("\nFactorial of %d is %d.\n", num, fact(num));

    return 0;
}
