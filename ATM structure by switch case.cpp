//WAP to print ATM structure by using switch case?
#include<stdio.h>

int main()
{
	int ch,balance=1000,amt,withdraw,credit;
	printf("enter choice");
	printf("1 for withdraw\n2 for credit\n3 for balance\n4 for exit");
	scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			withdraw = balance-amt;
			printf("withdraw amount is: %d", balance-amt);
			break;
			case 2:
credit = balance + amt;
printf("credit amount is: %d", balance + amt);
break;
case 3:
balance = balance;
printf("balance is: %d", balance);
break;
case 4:
printf("want to exit?");
if(ch==1)
{
	printf("exit the program");
	
				}
				else
				{
					printf("do not exit the program");
					
								}				
	}
}
