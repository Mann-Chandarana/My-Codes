#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], c[3][3], temp;
    printf("Enter first Matrix A\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("a[%d][%d] is :", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second Matrix B\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("b[%d][%d] is :", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix a is\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("a[%d][%d] is %d:\n", i, j, a[i][j]);
        }
    }
    printf("Matrix b is\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("b[%d][%d] is %d:\n", i, j, b[i][j]);
        }
    }
    /////// Multiplication of a matrix

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (temp = 0; temp < 3; temp++)
            {
                c[i][j] = c[i][j] + a[i][temp] * b[temp][j];
            }
        }
    }
    //// Resultant matrix C
    printf("Printing Matric C \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("c[%d][%d] is %d\n:",i, j, c[i][j]);
        }
    }

    return 0;
}