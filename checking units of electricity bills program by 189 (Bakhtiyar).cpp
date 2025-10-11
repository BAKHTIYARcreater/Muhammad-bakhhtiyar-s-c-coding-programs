//WAP to print electircity bills?
#include <stdio.h>

int main(void)
 {
    long units;
    double bill = 0.0;

    printf("Enter total electricity units consumed (integer): ");
    if (scanf("%ld", &units) != 1) 
{
        printf("Invalid input.\n");
        return 1;
    }

    if (units < 0) 
{
        printf("Units cannot be negative.\n");
        return 1;
    }

    if (units <= 100) 
{
        bill = units * 5.0;
    }
 else if(units <= 200) 
{
        bill = 100 * 5.0 + (units - 100) * 7.0;
    }
 else
 {
        bill = 100 * 5.0 + 100 * 7.0 + (units - 200) * 10.0;
    }

    printf("Total units: %ld\n", units);
    printf("Total bill: Rs %.2f\n", bill);

    return 0;
}
 

