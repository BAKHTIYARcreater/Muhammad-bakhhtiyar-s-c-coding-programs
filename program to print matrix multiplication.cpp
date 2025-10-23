#include<stdio.h>

int main(void)
{
	int i,j,k;
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[3][2] = {{7,8},{9,10},{11,12}};
	int c[2][2] = {0};

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<3;k++)
			c[i][j] += a[i][k] * b[k][j];
		}
	}

	printf("resultant matrix c[2x2]\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");		
	}
		return 0;	
}

