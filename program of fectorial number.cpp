//WAP to print fectorial numbers?
#include<stdio.h>
#include<conio.h>

min()
{
int i, num, fact=1;
printf("enter a number");
scanf("%d", &num);
for(i=num;i>=1;i--)
{6	

fact=fact*i;
	
}
printf("factorial of given number  is: %d\n",fact);
}
