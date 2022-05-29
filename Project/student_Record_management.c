#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float mark;
    struct Student *next;

} * head;

void insert(int rollnumber, char *name, char *phone, float mark)
{

    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->mark = mark;
    student->next = NULL;

    if (head == NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty 
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
}

void search(int rollnumber)
{
    struct Student *temp = head;
    while (temp != NULL)
    {
        if (temp->rollnumber == rollnumber)
        {
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Mark: %0.4f\n", temp->mark);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void update(int rollnumber)
{

    struct Student *temp = head;
    while (temp != NULL)
    {

        if (temp->rollnumber == rollnumber)
        {
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new mark: ");
            scanf("%f", &temp->mark);
            printf("Updated Successfully!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void Delete(int rollnumber)
{
    struct Student *temp1 = head;
    struct Student *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->rollnumber == rollnumber)
        {

            printf("Record with roll number %d Found !!!\n", rollnumber);

            if (temp1 == temp2)
            {
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else
            {
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void display()
{
    struct Student *temp = head;
    while (temp != NULL)
    {

        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Mark: %0.4f\n\n", temp->mark);
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float mark;

    do
    {
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Insert student details");
        printf("\n 2. Search student details");
        printf("\n 3. Delete Student Details");
        printf("\n 4. Update student details");
        printf("\n 5. Display all student details");
        printf("\n 6. EXIT");
        printf("\n \nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter roll number: ");
            scanf("%d", &rollnumber);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            printf("Enter mark: ");
            scanf("%f", &mark);
            insert(rollnumber, name, phone, mark);
            break;
        case 2:
            printf("\n Enter roll number to search: ");
            scanf("%d", &rollnumber);
            search(rollnumber);
            break;
        case 3:
            printf("\n Enter roll number to delete: ");
            scanf("%d", &rollnumber);
            Delete(rollnumber);
            break;
        case 4:
            printf("\n Enter roll number to update: ");
            scanf("%d", &rollnumber);
            update(rollnumber);
            break;
        case 5:
            display();
            break;
        }

    } while (choice != 6);
}