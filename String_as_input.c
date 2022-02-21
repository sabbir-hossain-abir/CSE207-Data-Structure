#include <stdio.h>
#include <conio.h>

int main()
{
    char name[20];
    printf("Enter your name: \n");
    // scanf("%c", "name");
    fgets(name, 20, stdin);
    printf("Your name is %s", name);
    return 0;
}