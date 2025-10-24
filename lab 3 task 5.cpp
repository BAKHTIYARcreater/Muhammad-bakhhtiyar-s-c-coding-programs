#include<stdio.h>

int main(void)
{
	long long num,temp;
	printf("Enter a number: ");
	scanf("%lld",&num);
	temp=num;
	while(temp>9||temp<-9)
	{
		int lastDigit=temp%10;
		temp=temp/10;
		temp=temp-2*lastDigit;
	}
	if(temp==0||temp==7||temp==-7)
		printf("%lld is divisible by 7.\n",num);
	else
		printf("%lld is not divisible by 7.\n",num);
}

