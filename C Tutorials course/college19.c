#include <stdio.h>

int chechPrimeNumber(int n);

int main()
{
    int n, count;
    printf("Enter the positive integer\n");
    scanf("%d", &n);
    count = chechPrimeNumber(n);
    if (count == 1)
    {
        printf("It is prime number\n");
    }
    else
    {
        printf("It is not a prime number\n");
    }

    return 0;
}

int chechPrimeNumber(int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    return count;
}
