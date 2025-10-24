#include <stdio.h>

void fib_using_for()
{
    printf("Fibonacci using for loop (<=1000):\n");
    int a = 1, b = 1;
    printf("%d %d", a, b);
    for (;;)
    {
        int c = a + b;
        if (c > 1000)
            break;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");
}

void fib_using_while()
{
    printf("Fibonacci using while loop (<=1000):\n");
    int a = 1, b = 1;
    printf("%d %d", a, b);
    while (1)
    {
        int c = a + b;
        if (c > 1000)
            break;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main()
{
    fib_using_for();
    fib_using_while();

    int a = 1, b = 1;
    long long sum = 0;

    if (a <= 1000 && (a % 3 == 0 || a % 5 == 0 || a % 7 == 0))
        sum += a;
    if (b <= 1000 && (b % 3 == 0 || b % 5 == 0 || b % 7 == 0))
        sum += b;

    while (1)
    {
        int c = a + b;
        if (c > 1000)
            break;
        if (c % 3 == 0 || c % 5 == 0 || c % 7 == 0)
            sum += c;
        a = b;
        b = c;
    }

    printf("Sum of Fibonacci numbers <=1000 divisible by 3 or 5 or 7 = %lld\n", sum);
    return 0;
}

