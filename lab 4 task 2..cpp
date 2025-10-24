#include <stdio.h>
#include <ctype.h>

void displayInstructions(char type, int isDouble, int isManual)
{
    printf("\n--- Coffee Preparation Instructions ---\n");

    if (type == 'B')
    {
        printf("1) Grind beans.\n");
        printf("2) Brew black coffee.\n");
        printf("3) Dispense into cup.\n");
    }
    else
    {
        printf("1) Grind beans.\n");
        printf("2) Brew coffee.\n");
        printf("3) Steam/add milk (white coffee).\n");
        printf("4) Dispense into cup.\n");
    }

    if (isDouble)
        printf("Note: Cup size is double -> baking time increased by 50%%.\n");

    if (isManual)
        printf("Manual mode: the machine will wait for user confirmations between steps.\n");
    else
        printf("Automatic mode: the machine will perform steps automatically.\n");

    printf("----------------------------------------\n");
}

double computeCoffeeTime(char type, int isDouble)
{
    double time = 0.0;

    if (type == 'B')
        time = 5.0 + 25.0 + 5.0;
    else
        time = 6.0 + 30.0 + 10.0 + 5.0;

    if (isDouble)
        time = time * 1.5;

    return time;
}

int main(void)
{
    char type;
    char cDouble, cManual;
    int isDouble = 0, isManual = 0;

    printf("Enter coffee type (B for Black, W for White): ");
    if (scanf(" %c", &type) != 1)
        return 0;

    type = toupper(type);

    printf("Is the cup size double? [Y/y] / [N/n]: ");
    if (scanf(" %c", &cDouble) != 1)
        return 0;

    cDouble = toupper(cDouble);
    isDouble = (cDouble == 'Y') ? 1 : 0;

    printf("Is the coffee manual? [Y/y] / [N/n]: ");
    if (scanf(" %c", &cManual) != 1)
        return 0;

    cManual = toupper(cManual);
    isManual = (cManual == 'Y') ? 1 : 0;

    if (type != 'B' && type != 'W')
    {
        printf("Invalid coffee type. Please enter B or W.\n");
        return 0;
    }

    displayInstructions(type, isDouble, isManual);
    double total = computeCoffeeTime(type, isDouble);
    printf("Total machine time required: %.1f seconds\n", total);

    return 0;
}

