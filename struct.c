#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Student
{
    char name[50];
    int age;
    float gpa;
    
};

void x(char name[], int age, double gpa)
{
    printf("%s %d %.2f", name, age, gpa);
}

int main()
{
    struct Student student1 = {"Sabah", 22, 5.00};
    x(student1.name, student1.age, student1.gpa);

    return 0;
}