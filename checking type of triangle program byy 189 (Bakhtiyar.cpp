#include <stdio.h>

int main(void)
{
    double a, b, c;

    printf("Enter 3 sides of triangle: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    /* check for non-positive sides */
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Sides must be positive numbers.\n");
        return 1;
    }

    
    if (!((a + b > c) && (a + c > b) && (b + c > a))) {
        printf("The given sides do not form a proper triangle.\n");
        return 1;
    }

    
    if (a == b && b == c) {
        printf("The triangle is equilateral.\n");
    } else if (a == b || b == c || a == c) {
        printf("The triangle is isosceles.\n");
    } else {
        printf("The triangle is scalene.\n");
    }

    return 0;
}
