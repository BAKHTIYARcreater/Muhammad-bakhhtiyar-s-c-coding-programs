//WAP to print standered calculator by using switch?
#include<stdio.h>

int main()
{
	int a,b,result,ch;
	printf("enter first number");
	scanf("%d", &a);
	printf("enter second number");
	scanf("%d", &b);
printf("enter your choice");
printf("1 for addition\n2 for subtraction\n3 for multiplicatio\n4 or division\n5 for modulus");
scanf("%d", &ch);
switch(ch)
{
	case  1:
		result = a+b;
		printf("result of addition is: %d", a+b);
		break;
		case 2:
			result = a-b;
			printf("result of subtraction is: %d", a-b);
			break;
			
			case 3:
				result = a*b;
				printf("result of multiplication is: %d", a*b);
				break;
				case 4:
if(b==0)
{
	printf("division by 0 is not allowed");
	
					}
					else
					{
						printf("result is a/b");
						
										}
										printf("result of division is: %d", a/b);
										break;
										case 5:
										if(b==0)
										{
											printf("modulus with 0 is not allowed");
															}
															else
															{
																printf("result is a%b");
																
																				}
																				printf("result of modulus is: %d", a%b);
																				break;
																				default:
																				printf("invalid operator choosed");					
}
}
