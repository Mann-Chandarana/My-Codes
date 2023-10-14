#include <stdio.h>
#include <string.h>

int main()
{
    int n, i,sum = 0;
    printf("Enter your number\n");
    scanf("%d", &n);
    for (i = 1 ; i <=(n-1); i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        };
    }
    if (sum == n)
    {
        printf("The number enterd is %d and it is a perfect number",n);
    }
    else
    {
        printf("The number enterd is %d and it is not a perfect number",n);
    }

    return 0;
}