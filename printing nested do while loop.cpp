#include <stdio.h>

int main() {
    int i = 1, j, k;   // i = hundreds, j = tens, k = ones

    printf("3-digit Special Numbers (sum of digits = 9):\n");

    do { // hundreds place (1 to 9)
        j = 0;
        do { // tens place (0 to 9)
            k = 0;
            do { // ones place (0 to 9)
                if (i + j + k == 9) {
                    int num = i * 100 + j * 10 + k;
                    printf("%d\n", num);
                }
                k++;
            } while (k <= 9);
            j++;
        } while (j <= 9);
        i++;
    } while (i <= 9);

    return 0;
}

