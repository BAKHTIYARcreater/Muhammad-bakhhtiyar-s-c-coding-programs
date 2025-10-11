//WAP to print corses for first year or second year according to the user response
#include <stdio.h>

int main()
 {
    int progtype,year;

    printf("Select Program Type:\n");
    printf("1. Computer Science\n");
    printf("2. Electrical Engineering\n");
    printf("Enter your choice: ");
    scanf("%d", &progtype);

switch(progtype) 
{
        case 1:
            printf("\nYou selected Computer Science.\n");
            printf("Enter Year:\n");
            printf("1. First Year\n");
            printf("2. Second Year\n");
            printf("Enter your choice: ");
            scanf("%d", &year);

            switch (year) {
                case 1:
                    printf("\nCourses for Computer Science - First Year:\n");
                    printf("1. Programming Fundamentals\n");
                    printf("2. Calculus\n");
                    printf("3. Physics\n");
                    printf("4. Introduction to Computing\n");
                    break;
                case 2:
                    printf("\nCourses for Computer Science - Second Year:\n");
                    printf("1. Data Structures\n");
                    printf("2. Computer Organization\n");
                    printf("3. Discrete Mathematics\n");
                    printf("4. Object Oriented Programming\n");
                    break;
                default:
                    printf("\nInvalid Year Selection.\n");
            }
            break;

        case 2:
            printf("\nYou selected Electrical Engineering.\n");
            printf("Enter Year:\n");
            printf("1. First Year\n");
            printf("2. Second Year\n");
            printf("Enter your choice: ");
            scanf("%d", &year);

            switch (year) {
                case 1:
                    printf("\nCourses for Electrical Engineering - First Year:\n");
                    printf("1. Basic Electrical Engineering\n");
                    printf("2. Engineering Mathematics\n");
                    printf("3. Physics\n");
                    printf("4. Workshop Practice\n");
                    break;
                case 2:
                    printf("\nCourses for Electrical Engineering - Second Year:\n");
                    printf("1. Circuit Analysis\n");
                    printf("2. Electronic Devices\n");
                    printf("3. Signals and Systems\n");
                    printf("4. Electromagnetic Theory\n");
                    break;
                default:
                    printf("\nInvalid Year Selection.\n");
            }
            break;

        default:
            printf("\nInvalid Program Type Selection.\n");
    }

    return 0;
}
