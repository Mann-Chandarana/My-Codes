#include <stdio.h>

int main()
{
    int rows;
    printf("Enter the number of rows you want\n");
    scanf("%d", &rows);
    int k = 1;
    for (int i = 0; i <= rows; i++)
    {
        for (int space = 0; space < i; space++)
        {
            printf(" ");
        }
        for (int j = 0; j < (2*rows-k); j++)
        {
            printf("*");
        }
        printf("\n");
        k=k+2;
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");

    return 0;
}
