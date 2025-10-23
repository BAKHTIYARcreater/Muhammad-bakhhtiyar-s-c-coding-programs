#include<stdio.h>

int main(void)
{
    int i, j, k;
    int r1, c1, r2, c2;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2)
    {
        printf("Matrix multiplication not possible! (columns of A != rows of B)\n");
        return 0;
    }

    int a[r1][c1], b[r2][c2], c[r1][c2];

    // Initialize matrix c to 0
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            c[i][j] = 0;
        }
    }

    printf("Enter elements of matrix A:\n");
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            for(k=0; k<c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Resultant matrix c[%dx%d]\n", r1, c2);
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

