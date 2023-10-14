#include <stdio.h>
#include <string.h>

int main()
{
    int n, count = 0;
    printf("Enter Your number\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        printf("You entered a number %d and the number is a prime number",n);
    }
    else
    {
        printf("You entered a number %d and the number is not a prime number",n);
    }

    return 0;
}