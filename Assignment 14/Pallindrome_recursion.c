#include <stdio.h>

int reverse(int n, int temp)
{
    // base case
    if (n == 0)
        return temp;

    // stores the reverse of a number
    temp = (temp * 10) + (n % 10);

    return reverse(n / 10, temp);
}

int main()
{

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int temp = reverse(n, 0);

    if (temp == n)
        printf("Pallindrome");
    else
        printf("Not Pallindrome");
    return 0;
}