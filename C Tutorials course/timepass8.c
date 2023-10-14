#include <stdio.h>

int main()
{
    int index, developerSalary[5], count = 0;
    printf("Enter the salary of 5 developers\n");
    for (index = 0; index < 5; index++)
    {
        scanf("%d", &developerSalary[index]);
    }
    for (index = 0; index < 5; index++)
    {
        if (developerSalary[index] > 50000)
        {
            count++;
        }
    }
    printf("Number of developers with salary greater than 50000 are %d\n", count);

    return 0;
}