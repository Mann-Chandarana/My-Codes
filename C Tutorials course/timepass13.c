#include <stdio.h>

int main()
{
    int n, temp;
    printf("Enter the number of rows\n");
    scanf("%d", &n);
    temp = n * 2 - 1;
    for (int i = 1; i <= temp; i++)
    {
        for (int j = 1; j <= temp; j++)
        {
            if (j == i || (j == temp - i + 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");

    return 0;
}