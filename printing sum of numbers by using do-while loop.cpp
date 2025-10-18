#include <stdio.h>

int main() {
    int num, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    do {
        digit = num % 10;   // extract last digit
        sum += digit;       // add to sum
        num /= 10;          // remove last digit
    } while (num != 0);

    printf("Sum of digits = %d\n", sum);

    return 0;
}

