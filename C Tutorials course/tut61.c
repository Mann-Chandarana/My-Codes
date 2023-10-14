#include <stdio.h>

int main()
{
    int m, n, sum = 0;
    int a[3][4], b[4][2], result[3][2];
    printf("Enter your first matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
        // printf("\n");
    }
    printf("Enter your second matrix\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Multiplying your matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 2; j++)
        {
            for (int k = 0; i < 4; k++)
            {
                sum += a[i][k] * a[k][j];
            }
            result[i][j] = sum;
            sum=0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\n",result[i][j]);
        }
    }

    return 0;
}