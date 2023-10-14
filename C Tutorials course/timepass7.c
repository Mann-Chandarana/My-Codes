#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int choice, n,count=0;
    int fact=1,sum=0;
    do
    {
        printf("\nPress\n 1. Prime number or not\n 2. Perfect number or not\n 3. Factorial of a number\n 4.Exit\n");
        printf("Enter Your choice\n");
        scanf("%d", &choice);

        if(choice != 4)
        {
            printf("Enter your number\n");
            scanf("%d", &n);
        }
        switch (choice)
        {
        case 1:
            for (int i = 1; i <= n; i++)
            {
                if (n % i == 0)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                printf("You entered a number %d and the number is a prime number\n", n);
            }
            else
            {
                printf("You entered a number %d and the number is not a prime number\n", n);
            }
            break;

        case 2:
            for (int i = 1; i <= (n - 1); i++)
            {
                if (n % i == 0)
                {
                    sum = sum + i;
                };
            }
            if (sum == n)
            {
                printf("The number enterd is %d and it is a perfect number\n", n);
            }
            else
            {
                printf("The number enterd is %d and it is not a perfect number\n", n);
            }
            break;

        case 3:
            for (int i = 1; i <= n; i++)
            {
                fact = fact * i;
            }
            printf("The Factorial of the number %d is %d\n", n, fact);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice\n");
            break;
        }

    } while (choice != 4);

    return 0;
}