#include <stdio.h>
#include <conio.h>

struct Student
{
    int age;
    double gpa;
    char name[20];
};


int main(){
    struct Student student1;
        student1.age=12;
        student1.gpa=2.7;
        strcpy(student1.name, "Sabbir");

        printf("%d", student1.age);
    
    return 0;
}