#include <stdio.h>

int main(void) {
    unsigned int x;
    const unsigned int mask4 = 1u << 3;
    const unsigned int mask7 = 1u << 6;

    printf("Enter an 8-bit unsigned integer (0-255): ");
    if (scanf("%u", &x) != 1) return 1;
    x &= 0xFFu;

    printf("Original value: %u (0x%02X)\n", x, x);

    if (x & mask4) {
        printf("4th bit is ON — turning it OFF.\n");
        x &= ~mask4;
    } else {
        printf("4th bit is already OFF.\n");
    }

    if (x & mask7) {
        printf("7th bit is ON — turning it OFF.\n");
        x &= ~mask7;
    } else {
        printf("7th bit is already OFF.\n");
    }

    printf("Resulting value: %u (0x%02X)\n", x, x);
    return 0;
}
