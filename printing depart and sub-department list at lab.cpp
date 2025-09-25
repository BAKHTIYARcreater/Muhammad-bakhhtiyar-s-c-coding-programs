//WAP to print departments and sub-departments?
#include<stdio.h>

int main(void)
{
	int dept, subd;
	printf("enter department");
	scanf("%d", &dept);
	switch(dept)
	{
		case 1:
			printf("computer science");
			
printf("choos your sub-department");
	scanf("%d", &subd);
	
			
			switch(subd)
			{
				case 1:
					printf("BSAI");
					break;
					case 2:
						printf("BSDS");
						break;
						case 3:
							printf("BScs");
							break;
							default:
								printf("no sub-depart available here");
								break;
						
			}
			
			case 2:
				printf("electrical enginiering");
				break;
				case 3:
					printf("humanities");
					break;
					default:
						printf("no depart here");
						break;
	}
	return 0;
	
}
