#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float gpa;
};

int main()
{
    struct Student *ptr;

    ptr = (struct Student *)malloc(sizeof(struct Student));

    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    ptr->id = 101; //Pointer using arrow operator
    strcpy(ptr->name, "Sajjad Hossain");
    (*ptr).gpa = 4.00; //Pointer using dot operator

    printf("Student Data:\n");
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("GPA: %.2f\n", ptr->gpa);

    free(ptr);

    return 0;
}
/* Output:

Student Data:
ID: 101
Name: Sajjad Hossain
GPA: 4.00

*/