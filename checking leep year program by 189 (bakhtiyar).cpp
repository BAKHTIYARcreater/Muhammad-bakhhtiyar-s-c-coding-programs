//WAP to check leep year?
#include<stdio.h>

int main(void)
{
	int year;
	printf("enter year");
	scanf("%d", &year);
	if(year%4==0 or year%400==0)
	{
		printf("its leep year");
		
	}
	else if(year%100==0)
	{
		printf("not a leep year");
		
	}
	else
	{
		printf("not leep year");
	}


}
