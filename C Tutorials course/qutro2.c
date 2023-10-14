#include <stdio.h>

int main()
{
    int A[3][3], AT[3][3];
    printf("Enter your numbers\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("The value of A[%d][%d] is %d\n", i, j, A[i][j]);
        }
    }
    printf("Transpose of Matrix is\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            AT[i][j] = A[j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("The value of AT[%d][%d] is %d\n", i, j, AT[i][j]);
        }
    }

    return 0;
}