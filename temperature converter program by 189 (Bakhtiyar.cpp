//WAP to print temperature from celsius to fahrenheit?
#include<stdio.h>

int main(void)
{
	float celsius, fahrenheit;
	printf("enter temperature of your area in celsius");
	scanf("%f", &celsius);
	    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
	    
	    if (celsius>=30)
	    {
	    	printf("it is hot weather, stay hyderaded");
		}
		else if(celsius>=20)
		
		{
			printf("perfect weather for outdoor activities");
		}
		else if(celsius>=10)
		
		
	{
		printf("some cold weather");
	}
	else
	{
		printf("wear jeckets and use blanckets");
	}
}
