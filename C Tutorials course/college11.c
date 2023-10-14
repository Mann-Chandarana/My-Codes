#include <stdio.h>

int main()
{
    int n = 21, p, o;
    while (1)
    {
        printf("\nNo of matches left=%d\n", n);
        printf("Pick up 1,2,3 or 4 matches\n");
        scanf("%d", &p);
        if (p > 4 || p < 1)
        {
            continue;
        }
        n = n - p;
        printf("\nNo of Matches left are %d\n", n);
        o = 5 - p;
        printf("\nOut of which computer picked up %d", o);
        n = n - o;
        if (n == 1)
        {
            printf("\nNo of matches left = %d", m);
            printf("\nYou lost the game");
            break;
        }
    }

    return 0;
}