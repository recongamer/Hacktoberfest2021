#include <stdio.h>
#include <conio.h>

void main()
{
    int a[10][10], b[10][10], c[10][10], sum[10][10], i, j, m, n, p, k;
    printf("enter the no of rows in first matrix: ");
    scanf("%d", &m);
    printf("enter the the no of columns in first matrix and rows in Second matrix. ONLY ENTER THE ONE VALUE: ");
    scanf("%d", &n);
    printf("enter the no of columns in second matrix: ");
    scanf("%d", &p);
    printf("enter first matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    printf("enter second matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
            scanf("%d", &b[i][j]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
            printf("%3d", b[i][j]);
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            sum[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] = a[i][k] * b[k][j];
                sum[i][j] = sum[i][j] + c[i][j];
            }
        }
    }
    printf("multiplication is \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
            printf(" %3d ", sum[i][j]);
        printf("\n");
    }
    getch();
}