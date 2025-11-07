//WAP to print swap values by using function?
#include<stdio.h>

void swap(int * a, int * b)
{
int temp = *a;
	*a = *b;
*b=temp;
	
}
int main(void)
{
	int x=20, y=27;
	    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}


