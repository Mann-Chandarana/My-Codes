#include <stdio.h>
void main()
{
    char *s[] = {
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"};

    char *p;
    int i, count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (p = s[i]; *p; p++)
        {
            if (*p == 'e')
            {
                count++;
            }
        }
    }
    printf("Total no of 'e' is %d\n", count);
}