#include <stdio.h>

int main(void)
{
    double nts, fsc;

    printf("Enter your F.Sc percentage: ");
    if (scanf("%lf", &fsc) != 1)
        return 0;

    printf("Enter your NTS percentage: ");
    if (scanf("%lf", &nts) != 1)
        return 0;

    printf("\nAssessment result:\n");

    if (fsc > 70.0 && nts >= 70.0)
        printf("Allocated: OxfordIT\n");
    else if (fsc > 70.0 && nts >= 60.0)
        printf("Allocated: Electronics\n");
    else if (fsc > 70.0 && nts >= 50.0)
        printf("Allocated: Telecommunication\n");
    else if (fsc >= 60.0 && fsc <= 70.0 && nts >= 50.0)
        printf("Allocated: MITIT\n");
    else if (fsc >= 50.0 && fsc <= 59.0 && nts >= 50.0)
        printf("Allocated: Chemical\n");
    else if (fsc > 40.0 && fsc < 50.0 && nts >= 50.0)
        printf("Allocated: Computer\n");
    else
        printf("No seat allocated based on provided criteria.\n");

    return 0;
}

