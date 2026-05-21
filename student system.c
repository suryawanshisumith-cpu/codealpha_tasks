#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
};

void add()
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "a");

    if(fp == NULL)
    {
        printf("File Error\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    fprintf(fp, "%d %s\n", s.roll, s.name);

    fclose(fp);

    printf("Record Added\n");
}

void display()
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("\nStudent Records\n");

    while(fscanf(fp, "%d %s", &s.roll, s.name) == 2)
    {
        printf("Roll: %d  Name: %s\n",
               s.roll, s.name);
    }

    fclose(fp);
}

void search()
{
    FILE *fp;
    struct Student s;

    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s", &s.roll, s.name) == 2)
    {
        if(s.roll == roll)
        {
            printf("\nStudent Found\n");
            printf("Roll: %d\n", s.roll);
            printf("Name: %s\n", s.name);

            found = 1;
        }
    }

    if(found == 0)
        printf("Record Not Found\n");

    fclose(fp);
}

void deleteRecord()
{
    FILE *fp, *temp;

    struct Student s;

    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s", &s.roll, s.name) == 2)
    {
        if(s.roll != roll)
        {
            fprintf(temp,
                    "%d %s\n",
                    s.roll,
                    s.name);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt",
           "student.txt");

    if(found)
        printf("Record Deleted\n");
    else
        printf("Record Not Found\n");
}

void update()
{
    FILE *fp, *temp;

    struct Student s;

    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s", &s.roll, s.name) == 2)
    {
        if(s.roll == roll)
        {
            printf("Enter New Name: ");
            scanf("%s", s.name);

            found = 1;
        }

        fprintf(temp,
                "%d %s\n",
                s.roll,
                s.name);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt",
           "student.txt");

    if(found)
        printf("Record Updated\n");
    else
        printf("Record Not Found\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");

        printf("1.Add\n");
        printf("2.Delete\n");
        printf("3.Update\n");
        printf("4.Search\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add();
                break;

            case 2:
                deleteRecord();
                break;

            case 3:
                update();
                break;

            case 4:
                search();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program Closed\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    }
    while(choice != 6);

    return 0;
}