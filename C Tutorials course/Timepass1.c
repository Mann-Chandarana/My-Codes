#include <stdio.h>

int main()
{
    int Shyamage, Rajuage, Ajayage;

    printf("Enter the age Of Shyam\n");
    scanf("%d", &Shyamage);
    if (Shyamage > 100)
    {
        printf("\nEnter valid age\n");
        return 0;
    }

    printf("Enter the age Of Raju\n");
    scanf("%d", &Rajuage);
    if (Rajuage > 100)
    {
        printf("\nEnter valid age\n");
        return 0;
    }

    printf("Enter the age Of Ajay\n");
    scanf("%d", &Ajayage);
    if (Ajayage > 100)
    {
        printf("\nEnter valid age\n");
        return 0;
    }

    switch (Shyamage > Rajuage)
    {
    case 1:
        switch (Rajuage < Ajayage)
        {
        case 1:
            printf("Raju is Youngest\n");
            break;
        case 0:
            printf("Ajay is Youngest\n");
            break;
        };
        break;
    case 0:
        switch (Shyamage > Ajayage)
        {
        case 1:
            printf("Ajay is Youngest\n");
            break;

        case 0:
            printf("Shyam is Youngest\n");
            break;
        };
        break;
    };

    return 0;
}