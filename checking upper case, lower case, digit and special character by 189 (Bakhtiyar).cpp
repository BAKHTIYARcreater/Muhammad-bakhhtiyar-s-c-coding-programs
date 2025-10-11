//WAP to print special characters, upper and lower letters?
#include<stdio.h>

int main(void)
{
	char ch;
	printf("enter single character");
	scanf("%c", &ch);
	if(ch=='A' && ch<='Z')
	{
		printf("upper case");
		
	}
	else if(ch<='a' && ch<='z')
	{
		printf("lower case");
		
	}
	else if(ch<=0 && ch<=9)
	{
		printf("it is a digit");
		
	} else
	{
		printf("it is a special caracter");
		
	}
}
