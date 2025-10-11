//WAp to print ggrade?
#include<stdio.h>

int main()
{
	int grade;
	float per;
	printf("enter your percentage");
	scanf("%f", &per);
	if(per>=90)
	{
		printf("A grade");
		
	}
	else if(per>=80)
	{
		printf("B grade");
		
	}
	else if(per>=70)
	{
		printf("c grade");
		
	}
	else if(per>=60)
	{
		printf("d grade");
		
	}
	else if(per>=50)
	{
		printf("E grade");
		
	}
	else
	{
		printf("you are fail");
		
	}

	
}
