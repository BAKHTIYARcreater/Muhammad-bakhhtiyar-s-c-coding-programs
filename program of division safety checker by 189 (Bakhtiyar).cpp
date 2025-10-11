//WAP to print division safety checker?
#include<stdio.h>

int main(void)
{
	float num1,num2,result;
	printf("enter divident number");
	scanf("%f", &num1);
	printf("enter diviser number");
	scanf("%f", &num2);
	
	if(num2==0)
	{
		printf("division is not possible");
		
	}
	else
	{
		result  = num1/num2;
		
		printf("result of division is: %2f/%2f = %2f", num1,num2,result);
	}
}
