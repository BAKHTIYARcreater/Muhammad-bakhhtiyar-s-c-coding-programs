#include<stdio.h>

int main(void)
{
	float texrate,grosspay,tex,netpay;
	printf("enter tex rate");
	scanf("%f", &&texrate);
	printf("enter grosspay");
	scanf("%f", &grosspay);
	tex = texrate*grosspay/100;
	printf("applied tex is: %f", tex);
	netpay = grosspay-tex;
	printf("netpay is: %f", netpay);
}
