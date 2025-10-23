//WAP the print program to format specifier
#include<stdio.h>
#include<conio.h>

main()	{
	int rollno;
	char name[50];
	float per;
	char grade;
	
	printf("Enter your roll no: ");
	scanf("%d",&rollno);
	
	printf("Enter your name: ");
	scanf("%s",name);
	
	printf("Enter your percentage: ");
	scanf("%f",&per);
	
	printf("Enter your grade: ");
	scanf("\n%c",&grade);
	
	printf("Your Roll No is: %d\n",rollno);
	printf("YOUR NAME IS: %s\n",name);
	printf("YOUR PERCENTAQGE IS: %f\n",per);
	printf("your grade is:  %c", grade);
	
}
