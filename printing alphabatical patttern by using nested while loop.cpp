#include <stdio.h>

int main() {
    char ch = 'A';  // starting character
    int i = 1;

    while (i <= 5) {  // outer loop for rows
        int j = 1;
        while (j <= i) {  // inner loop for printing characters
            printf("%c ", ch);
            j++;
        }
        printf("\n");
        ch++;  // move to next character (A ? B ? C ? D ? E)
        i++;
    }

    return 0;
}

