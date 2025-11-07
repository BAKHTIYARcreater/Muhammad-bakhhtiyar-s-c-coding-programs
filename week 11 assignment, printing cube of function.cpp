//WAP to print cube by using functions?
#include<stdio.h>

int cube(int x)
{
	return x * x * x;
}
int main(void)
{
	int num;
	printf("enter number");
	scanf("%d", &num);
int result = cube(num);
printf("cube of %d is: %d\n", num,result);
return 0;	
}
