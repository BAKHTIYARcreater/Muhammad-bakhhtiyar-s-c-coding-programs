//WAP to print days by using switch case?
#include<stdio.h>

int main(void)
{
	int day;
	printf("enter day");
	scanf("%i", &day);
	switch(day)
	{
		case 1:
			printf("monday");
			break;
			case 2:
				printf("tuesday");
				break;
				case 3:
					printf("wednesday");
					break;
					case 4:
						printf("thirsday");
						break;
						case 5:
						printf("friday");
						break;
						case 6:
						printf("saturday");
						case 7:
						printf("sunday");
						break;
						default:
						printf("no day matches");
							}
}
