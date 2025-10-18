#include <stdio.h>

int main() {
    int num;

    do {
        printf("Enter a number (0 to stop): ");
        scanf("%d", &num);
    } while (num != 0);

    printf("You entered 0. Program ended.\n");

    return 0;
}

