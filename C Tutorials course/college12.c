#include <stdio.h>

int main()
{
    int arr[10], zero = 0, positive = 0, negative = 0, odd = 0, even = 0;
    printf("Enter the array elements\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] > 0)
        {
            positive++;
        }
        else if (arr[i] < 0)
        {
            negative++;
        }
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    printf("The number of zero in array are %d\n", zero);
    printf("The number of positive in array are %d\n", positive);
    printf("The number of negative in array are %d\n", negative);
    printf("The number of even in array are %d\n", even);
    printf("The number of odd in array are %d\n", odd);

    return 0;
}