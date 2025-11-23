#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
    char department[50];
};

int main() {
    struct Employee emp[5];
    int i, maxIndex = 0;

    // Input 5 employees
    for (i = 0; i < 5; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Enter Name: ");
        fflush(stdin);
        fgets(emp[i].name, sizeof(emp[i].name), stdin);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
        getchar(); // clear newline

        printf("Enter Department: ");
        fgets(emp[i].department, sizeof(emp[i].department), stdin);
    }

    // Find highest salary
    for (i = 1; i < 5; i++) {
        if (emp[i].salary > emp[maxIndex].salary) {
            maxIndex = i;
        }
    }

    // Print employee with highest salary
    printf("\n\nEmployee With Highest Salary:\n");
    printf("Name       : %s", emp[maxIndex].name);
    printf("ID         : %d\n", emp[maxIndex].id);
    printf("Salary     : %.2f\n", emp[maxIndex].salary);
    printf("Department : %s", emp[maxIndex].department);

    return 0;
}

