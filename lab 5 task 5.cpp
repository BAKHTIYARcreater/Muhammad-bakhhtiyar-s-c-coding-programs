#include <stdio.h>
#include <math.h>

double round_to(double value, int decimals)
{
    double factor = pow(10.0, decimals);
    return floor(value * factor + 0.5) / factor;
}

int main()
{
    double sum = 0.0;
    int found_314 = -1, found_3141 = -1, found_31415 = -1, found_314159 = -1;

    printf("n\tpi_approx\n");

    for (int n = 1; n <= 200000; ++n)
    {
        int k = n - 1;
        double term = pow(-1.0, k) / (2.0 * k + 1.0);
        sum += term;
        double pi_approx = 4.0 * sum;

        if (n <= 40)
            printf("%d\t%.10f\n", n, pi_approx);
        else if (n == 41)
            printf("... (omitting intermediate values)\n");

        if (found_314 == -1 && fabs(round_to(pi_approx, 2) - 3.14) < 1e-12)
            found_314 = n;
        if (found_3141 == -1 && fabs(round_to(pi_approx, 3) - 3.141) < 1e-12)
            found_3141 = n;
        if (found_31415 == -1 && fabs(round_to(pi_approx, 4) - 3.1415) < 1e-12)
            found_31415 = n;
        if (found_314159 == -1 && fabs(round_to(pi_approx, 5) - 3.14159) < 1e-12)
        {
            found_314159 = n;
            break;
        }
    }

    printf("\nFirst n giving approximation rounded to:\n");

    if (found_314 != -1)
        printf("3.14    -> n = %d\n", found_314);
    if (found_3141 != -1)
        printf("3.141   -> n = %d\n", found_3141);
    if (found_31415 != -1)
        printf("3.1415  -> n = %d\n", found_31415);
    if (found_314159 != -1)
        printf("3.14159 -> n = %d\n", found_314159);

    return 0;
}

