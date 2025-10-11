#include<stdio.h>

int main(void)
{
	int a,b,c;
	printf("enter first value");
	scanf("%d", &a);
	printf("enter second value");
	scanf("%d", &b);
	c=a;
	
	a=b;
	
	
	b=c;
	printf("the value of a is: %d", a);
	printf("value of b is: %d", b);
	return 0;
}
