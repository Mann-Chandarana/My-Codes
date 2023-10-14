#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int limit;
    int *arr;
    int sum = 0;
    scanf("%d", &limit);
    arr = (int *)malloc(limit * sizeof(int));
    for (int i = 0; i < limit; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < limit; i++)
    {
        printf("%d ", arr[i]);
    }
    for (int j = 0; j < limit; j++)
    {
        sum = sum + arr[j];
    }
    printf("\n%d", sum);
    free(arr);

    return 0;
}