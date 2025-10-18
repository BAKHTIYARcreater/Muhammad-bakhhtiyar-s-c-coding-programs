#include <stdio.h>

int main() {
    int i = 1;

    while (i <= 5) {  // outer loop for table number
        int j = 1;
        printf("Multiplication Table of %d:\n", i);

        while (j <= 10) {  // inner loop for each multiplication line
            printf("%d x %d = %d\n", i, j, i * j);
            j++;
        }

        printf("\n");  // blank line between tables
        i++;
    }

    return 0;
}

