//WAP to print sum of 2d array elemetns?
#include<stdio.h>

int main(void)
{
int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
int sum=0;
int rows=2, cols=3;
for(int i=0;i<rows;i++)
{
	for(int j=0;j<cols;j++)
	{
		sum += mat[i][j];
	}
	printf("sum of this 2d arrray lement is: %d", sum);
	}
	return 0;
}

