#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    printf("Assigning integer 10\n");
    d.i = 10;
    printf("int: %d, float: %f, char: %c\n", d.i, d.f, d.c);

    printf("\nAssigning float 5.5\n");
    d.f = 5.5;
    printf("int: %d, float: %f, char: %c\n", d.i, d.f, d.c);

    printf("\nAssigning char 'A'\n");
    d.c = 'A';
    printf("int: %d, float: %f, char: %c\n", d.i, d.f, d.c);

    return 0;
}

