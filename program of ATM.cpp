//WAP to create  ATM?
#include<stdio.h>
#include<conio.h>
#include<string.h>


main()
{	
	float x, y;
	printf("open your account");
	scanf("%f", &x);
	char p[5];   //for 4-digits PIN code + '\0'
	int attempt = 3;
for(i=1;i<=attempts;i++)
	{
	
	printf("enter four digits pin-code");
	scanf("%s\n", p);
if(p<=5)
{
	printf("pin code is correct");
	return 0; exit if correct

}
else
{
	printf("incorrect pin format. attempt %d of %d\n", i, attempts);
}

printf("too many wrong attempts. try again after one hour");
}
char ch;
printf("enter your choice");
	
	printf("\nc for cradet\nd for depossite\nb for ballance\n");
scanf("\n%c", &ch);

switch (ch)
{
	case 'c':
		printf("enter cradit ammount: \n ");
		scanf("%f", &y);
		x=x+y;
		printf("current amount: %f",x);
		break;
	
	
		case 'd':
printf("enter debit amount: \n");
scanf("%f", &y);
if (x>=y)
{
	x=x-y;
	printf("current balance is: %f", x);
	
}
else
{
	printf("in sufficient balance");
	
}
break;

case 'b':
	printf("amount in your account: %f",x);
	break;
	
	default:
	printf("no option is here");
	
	}
}
