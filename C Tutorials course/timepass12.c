#include <stdio.h>

int main()
{
    int totalrows=0;
    printf("Enter the rows\n");
    scanf("%d", &totalrows);
    int rows = 1;
    while (rows <= totalrows)
    {
        int space = 0;
        while (space < (totalrows - rows))
        {
            printf(" ");
            space++;
        }
        int stars = 0;
        while (stars < (rows - 1))
        {
            printf("*");
            stars++;
        }
        printf("#");

        int amperstand = 0;
        while (amperstand < (rows - 1))
        {
            printf("&");
            amperstand++;
        }
        printf("\n");
        rows++;
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");

    return 0;
}