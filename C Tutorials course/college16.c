#include <stdio.h>

int main()
{
    char first[15], middle[15], last[15];

    printf("Enter First name\n");
    gets(first);

    printf("\nEnter middle name\n");
    gets(middle);

    printf("\nEnter last name\n");
    gets(last);

    printf("\n%c %c %s", first[0], middle[0], last);

    return 0;
}