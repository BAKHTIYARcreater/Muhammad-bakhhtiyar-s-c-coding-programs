#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    printf("Enter coefficients a, b and c (a != 0): ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (a == 0.0) {
        printf("Coefficient 'a' must not be zero for a quadratic equation.\n");
        return 1;
    }

    double D = b*b - 4.0*a*c;

    if (D > 0.0) {
        double r1 = (-b + sqrt(D)) / (2.0 * a);
        double r2 = (-b - sqrt(D)) / (2.0 * a);
        printf("Two distinct real roots:\n");
        printf("Root 1 = %.6f\n", r1);
        printf("Root 2 = %.6f\n", r2);
    } else if (D == 0.0) {
        double r = -b / (2.0 * a);
        printf("One real root (double root):\n");
        printf("Root = %.6f\n", r);
    } else {
        double real = -b / (2.0 * a);
        double imag = sqrt(-D) / (2.0 * a);
        printf("Two complex roots:\n");
        printf("Root 1 = %.6f + %.6fi\n", real, imag);
        printf("Root 2 = %.6f - %.6fi\n", real, imag);
    }
    return 0;
}

