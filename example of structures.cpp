#include<stdio.h>
#include<string.h>

struct student {
    int rollno;
    float marks;
    char name[20];
};

int main() {
    struct student s;

    printf("Enter roll no: ");
    scanf("%d", &s.rollno);

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\n--- Student Details ---\n");
    printf("Roll No: %d\n", s.rollno);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}

