#include <stdio.h>

int getgcd(int x, int y);

int main()
{
    int num1 = 0, num2 = 0;

    printf("Enter The Two Number for GCD \n");
    scanf("%d %d", &num1, &num2);
    int gcd;
    gcd = getgcd(num1, num2);
    printf("The GCD for %d , %d is %d\n", num1, num2, gcd);
}

int getgcd(int x, int y)
{
    if (x == 0)
        return y;
    else
        return getgcd(y % x, x);
}