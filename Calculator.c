#include <stdio.h>
#include <conio.h>
int main()
{
    char opt;
    double n1, n2;
    float res;
    printf(" Choose an operator \n ");
    scanf("%c", &opt);
    /* if (opt == '/')
    {
        printf("Division \n");
    }
    else if (opt == '*')
    {
        printf("Multiplication \n");
    }

    else if (opt == '-')
    {
        printf(" Subtraction \n");
    }
    else if (opt == '+')
    {
        printf("Addition \n");
    } */

    printf("Enter first number: ");
    scanf(" %lf", &n1);

    printf("Enter the second number: ");
    scanf(" %lf", &n2);

    switch (opt)
    {
    case '+':
        res = n1 + n2;
        printf(" Addition of %.2f and %.2f is: %.2f", n1, n2, res);
        break;

    case '-':
        res = n1 - n2;
        printf(" Subtraction of %.2f and %.2f is: %.2f", n1, n2, res);
        break;

    case '*':
        res = n1 * n2;
        printf(" Multiplication of %.2f and %.2f is: %.2f", n1, n2, res);
        break;
    case '/':
        res = n1 / n2;
        printf(" Devidation of %.2f and %.2f is: %.2f", n1, n2, res);
        break;
    default:
        printf("Invalid input");
    }
    return 0;
}