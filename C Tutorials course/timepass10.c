#include <stdio.h>

int main()
{
    int rows, space, n;
    printf("Enter the number of rows you want\n");
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        for (space = 0; space < (rows - i); space++)
        {
            printf(" ");
        }
        n = 1;
        for (int j = 0; j <= rows; j++)
        {
            if (n != 0)
            {
                printf("%d ", n);
            }
            n = n * (i - j) / (j + 1);
        }
        printf("\n");
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");

    return 0;
}
