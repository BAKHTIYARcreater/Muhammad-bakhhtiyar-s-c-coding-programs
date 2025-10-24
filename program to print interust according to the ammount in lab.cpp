#include <stdio.h>

int main() {
    float principal, rate, time, simpleInterest;

    // Input principal
    printf("Enter Principal amount (100 to 1000000 Rs): ");
    scanf("%f", &principal);

    if (principal < 100 || principal > 1000000) {
        printf("Error: Principal must be between 100 and 1000000 Rs.\n");
        return 0;
    }

    // Input rate
    printf("Enter Rate of Interest (5 to 10 %%): ");
    scanf("%f", &rate);

    if (rate < 5 || rate > 10) {
        printf("Error: Rate of Interest must be between 5%% and 10%%.\n");
        return 0;
    }

    // Input time
    printf("Enter Time Period (1 to 10 years): ");
    scanf("%f", &time);

    if (time < 1 || time > 10) {
        printf("Error: Time Period must be between 1 and 10 years.\n");
        return 0;
    }

    // Calculate Simple Interest
    simpleInterest = (principal * rate * time) / 100;

    printf("\nSimple Interest = %.2f Rs.\n", simpleInterest);

    return 0;
}
