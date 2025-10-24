
//WAP to print eid discount according to hte given conditions?#include <stdio.h>

int main(void) {
    double cost;
    double discount_pct = 0.0;

    printf("Enter total cost of shopping");
    if (scanf("%lf", &cost) != 1) return 1;

    if (cost <= 1999.0) {
        discount_pct = 0.0;
    } else if (cost >= 2000.0 && cost <= 4000.0) {
        discount_pct = 20.0;
    } else if (cost >= 4001.0 && cost <= 6000.0) {
        discount_pct = 30.0;
    } else if (cost > 6000.0) {
        discount_pct = 50.0;
    }

    double saved = (discount_pct / 100.0) * cost;
    double after = cost - saved;

    printf("Actual amount: %.2f\n", cost);
    printf("Saved amount:  %.2f (%.0f%%)\n", saved, discount_pct);
    printf("Amount after discount: %.2f\n", after);

    return 0;
}

