#include <stdio.h>

int main()
{
    int n;
    printf("Enter an odd positive integer for diamond width: ");
    if (scanf("%d", &n) != 1)
        return 0;

    if (n <= 0 || n % 2 == 0)
    {
        printf("Please enter a positive odd integer.\n");
        return 0;
    }

    int mid = n / 2;

    for (int i = 0; i <= mid; ++i)
    {
        int stars = 2 * i + 1;
        int spaces = (n - stars) / 2;

        for (int s = 0; s < spaces; ++s)
            putchar(' ');
        for (int t = 0; t < stars; ++t)
            putchar('*');
        putchar('\n');
    }

    for (int i = mid - 1; i >= 0; --i)
    {
        int stars = 2 * i + 1;
        int spaces = (n - stars) / 2;

        for (int s = 0; s < spaces; ++s)
            putchar(' ');
        for (int t = 0; t < stars; ++t)
            putchar('*');
        putchar('\n');
    }

    return 0;
}

