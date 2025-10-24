#include <stdio.h>

int main(void)
{
    char choice;
    printf("Are you sure to delete [Y/y] / [N/n] ? ");
    if (scanf(" %c", &choice) != 1)
        return 0;

    switch (choice)
    {
        case 'Y':
        case 'y':
            printf("Deleted successfully\n");
            break;
        case 'N':
        case 'n':
            printf("Delete cancelled\n");
            break;
        default:
            printf("choose the right option\n");
            break;
    }

    return 0;
}

