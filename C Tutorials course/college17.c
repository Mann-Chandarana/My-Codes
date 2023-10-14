// #include <stdio.h>

// void checkPrimeNumber();

// int main()
// {
//     checkPrimeNumber();

//     return 0;
// }
// void checkPrimeNumber()
// {
//     int n, i, temp = 0, count = 0;
//     printf("Enter the positive integer\n");
//     scanf("%d", &n);
//     for (int i = 1; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             count++;
//         }
//     }
//     if (count == 1)
//     {
//         printf("It is prime number\n");
//     }
//     else
//     {
//         printf("It is not a prime number\n");
//     }
// }
///////////////////
#include <stdio.h>
int getInteger();
int main()
{
    int count=0,n;
    getInteger();
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
    
    return 0;
}
int getInteger()
{
    int n;
    printf("Enter the positive integer\n");
    scanf("%d",&n);

    return n;
}