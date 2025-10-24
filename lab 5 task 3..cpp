#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0)
        return 0;

    int r = (int)sqrt((double)n);
    for (int i = 3; i <= r; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int num;
    printf("Enter a 5-digit number: ");
    if (scanf("%d", &num) != 1)
        return 0;

    if (num < 10000 || num > 99999)
    {
        printf("Error: not a 5-digit number.\n");
        return 0;
    }

    int temp = num, sum = 0, rev = 0;
    while (temp > 0)
    {
        int d = temp % 10;
        sum += d;
        rev = rev * 10 + d;
        temp /= 10;
    }

    if (sum % 2 == 0)
    {
        if (is_prime(num))
            printf("Sum of digits is even (%d). %d is PRIME.\n", sum, num);
        else
            printf("Sum of digits is even (%d). %d is NOT prime.\n", sum, num);
    }
    else
    {
        if (rev == num)
            printf("Sum of digits is odd (%d). %d is a PALINDROME.\n", sum, num);
        else
            printf("Sum of digits is odd (%d). %d is NOT a palindrome.\n", sum, num);
    }
    return 0;
}

