#include <stdio.h>

void chechPrimeNumber(int n);

int main()
{
    int n;
    printf("Enter the positive integer\n");
    scanf("%d",&n);
    chechPrimeNumber(n);
    
    return 0;
}
void chechPrimeNumber(int n)
{
    int count=0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        printf("It is prime number\n");
    }
    else
    {
        printf("It is not a prime number\n");
    }
}