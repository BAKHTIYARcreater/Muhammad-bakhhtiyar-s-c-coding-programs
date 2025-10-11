#include <stdio.h>

int main(void)
{
    int day, timing;

    printf("Enter day number (1 for Monday, 2 for Tuesday, 3 for Wednesday,\n");
    printf("                  4 for Thursday, 5 for Friday, 6 for Saturday, 7 for Sunday): ");
    if (scanf("%d", &day) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    printf("Select timing (1 = Morning, 2 = Evening): ");
    if (scanf("%d", &timing) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    switch (day) {
        case 1: // Monday
            switch (timing) {
                case 1:
                    printf("Monday Morning — Go to school.\n");
                    break;
                case 2:
                    printf("Monday Evening — Do homework.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 2: // Tuesday
            switch (timing) {
                case 1:
                    printf("Tuesday Morning — Attend math class.\n");
                    break;
                case 2:
                    printf("Tuesday Evening — Play football.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 3: // Wednesday
            switch (timing) {
                case 1:
                    printf("Wednesday Morning — Science practical.\n");
                    break;
                case 2:
                    printf("Wednesday Evening — Study English.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 4: // Thursday
            switch (timing) {
                case 1:
                    printf("Thursday Morning — Attend computer class.\n");
                    break;
                case 2:
                    printf("Thursday Evening — Read a book.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 5: // Friday
            switch (timing) {
                case 1:
                    printf("Friday Morning — Go to school.\n");
                    break;
                case 2:
                    printf("Friday Evening — Watch TV.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 6: // Saturday
            switch (timing) {
                case 1:
                    printf("Saturday Morning — Play sports.\n");
                    break;
                case 2:
                    printf("Saturday Evening — Hang out with friends.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        case 7: // Sunday
            switch (timing) {
                case 1:
                    printf("Sunday Morning — Rest at home.\n");
                    break;
                case 2:
                    printf("Sunday Evening — Watch a movie.\n");
                    break;
                default:
                    printf("Invalid timing option.\n");
            }
            break;

        default:
            printf("Invalid day. Choose a number from 1 to 7.\n");
    }

    return 0;
}
