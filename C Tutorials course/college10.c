#include <stdio.h>

int main()
{
    int n, choice;
    printf("Enter your choice\n");
    scanf("%d", &n);
    printf("1. For converting %d to octal number\n", n);
    printf("2. For converting %d to hexa decimal number\n", n);
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n%d of decimal system, in octal is %o", n, n);
        break;

    case 2:
        printf("\n%d of decimal system, in hexa decimal is %x", n, n);
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}