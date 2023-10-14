#include <stdio.h>

int main()
{
    int marks[10], *p;
    int distinction = 0, firstClass = 0, pass = 0, fail = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter marks for Student %2d \n", i + 1);
        scanf("%d", p);
        p++;
    }
    for (p = marks; p < &marks[10]; p++)
    {
        if (*p >= 70)
        {
            distinction++;
        }
        else if (*p <= 69 && *p >= 60)
        {
            firstClass++;
        }
        else if (*p <= 59 && *p >= 40)
        {
            pass++;
        }
        else
        {
            fail++;
        }
    }
    printf("\n\nDistinction : %d", distinction);
    printf("\nFirst class : %d", firstClass);
    printf("\nPass        : %d", pass);
    printf("\nFail        : %d", fail);
    return 0;
}
