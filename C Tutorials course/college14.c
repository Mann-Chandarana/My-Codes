#include <stdio.h>
int main()
{
    int A[3][3], B[3][3], C[3][3], sum;
    //////
    printf("Enter matrix A\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    //////

    printf("Matrix A is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("A[%d][%d] is %d ", i, j, A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("B[%d][%d] is %d ", i, j, B[i][j]);
        }
        printf("\n");
    }
    ////// Matrix Multiplication
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum = 0;
            for (int K = 0; K < 3; K++)
            {
                sum = sum + A[i][K] * B[K][j];
            }
            C[i][j] = sum;
        }
    }
    printf("Multiplication of a matrix is as follows\n");
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("C[%d][%d] is %d ", i, j, C[i][j]);
        }
        printf("\n");
    }

    return 0;
}