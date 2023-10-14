#include <stdio.h>

void starpattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void reversestarpattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= rows - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int rows, types;
    printf("Enter 0 for star pattern and 1 for reverse star pattern\n");
    scanf("%d", &types);
    printf("How many rows do you want ?\n");
    scanf("%d", &rows);
    switch (types)
    {
    case 0:
        starpattern(rows);
        break;

    case 1:
        reversestarpattern(rows);
        break;

    default:
        break;
    }
    return 0;
}