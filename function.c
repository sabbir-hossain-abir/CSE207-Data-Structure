#include <stdio.h>
#include <conio.h>

int min(int num1, int num2, int num3){

    int result;
    if (num1<=num2 && num1<=num3)
    {
        result=num1;
    }
    else if (num2<=num1 && num2<=num3)
    {
        result=num2;
    }
    else
    {
        result=num3;
    }
    return result;
    
    
}

int max(int num1, int num2, int num3)
{
    int result;
    if (num1 >= num2 && num1 >= num3)
    {
        result = num1;
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        result = num2;
    }
    else
    {
        result = num3;
    }
    return result;
}

int main()
{
    int num1, num2, num3;
    printf("Enter 1st number: \n");
    scanf("%d", &num1);
    printf("Enter 2nd number: \n");
    scanf("%d", &num2);
    printf("Enter 3rd number: \n");
    scanf("%d", &num3);
    printf("Max number is %d \n", max(num1, num2, num3));
    printf("Min number is %d \n", min(num1, num2, num3));
    return 0;
}