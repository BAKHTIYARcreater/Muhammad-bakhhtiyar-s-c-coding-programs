#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int types, i, qty;
    char choice;
    double total = 0.0;

    printf("Menu:\n");
    printf("B = Burger (Rs. 200)\n");
    printf("F = French Fries (Rs. 50)\n");
    printf("P = Pizza (Rs. 500)\n");
    printf("S = Sandwiches (Rs. 150)\n\n");

    printf("Enter number of types of snacks (2, 3, or 4): ");
    if (scanf("%d", &types) != 1)
        return 0;

    if (types < 2 || types > 4)
    {
        printf("Invalid number of types. Please enter 2, 3 or 4.\n");
        return 0;
    }

    for (i = 0; i < types; ++i)
    {
        printf("Enter choice #%d (B/F/P/S): ", i + 1);
        if (scanf(" %c", &choice) != 1)
            return 0;

        choice = toupper(choice);

        printf("Enter quantity for choice #%d: ", i + 1);
        if (scanf("%d", &qty) != 1 || qty < 0)
        {
            printf("Invalid quantity. Exiting.\n");
            return 0;
        }

        switch (choice)
        {
            case 'B':
                total += 200.0 * qty;
                break;
            case 'F':
                total += 50.0 * qty;
                break;
            case 'P':
                total += 500.0 * qty;
                break;
            case 'S':
                total += 150.0 * qty;
                break;
            default:
                printf("Invalid choice '%c'. This item skipped.\n", choice);
                break;
        }
    }

    printf("\nTotal charges for the order: Rs. %.2f\n", total);

    return 0;
}

