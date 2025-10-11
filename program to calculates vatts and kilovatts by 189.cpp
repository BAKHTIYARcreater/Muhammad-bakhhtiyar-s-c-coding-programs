//WAP to print vatts in to kilovatts?
#include<stdio.h>

int main(void)
{
	float vatts, kilovatts;
	printf("enter vatts");
	scanf("%f", &vatts);
kilovatts = vatts/1000;
	printf("kilovatts is: %2f", kilovatts);
	return 0;
}
