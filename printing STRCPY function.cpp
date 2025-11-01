//WAP to print STRCPY string funtion?
#include<stdio.h>
#include<string.h>

int main(void)
{
	char src[] = "hello";
	char dest[10];
	strcpy (dest, src);
	printf("dest = %s\n", dest);
	return 0;
	
}
