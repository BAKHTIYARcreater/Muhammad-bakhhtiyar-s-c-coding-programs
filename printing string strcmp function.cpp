//WAP to print strcmp string function?
#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "World";
    char dest[4];

    strncpy(dest, src, 3);
    dest[3] = '\0';

    printf("%s\n", dest);

    return 0;
}

