#include <stdio.h>

int main()
{
    int A[15], size, temp;
    printf("Enter the size of an array\n");
    scanf("%d", &size);
    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("The element of A[%d] is %d\n", i, A[i]);
    }
    printf("Sorting the elements");
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (A[i] >= A[j])
            {
                temp=A[i];
                A[i] = A[j];
                A[j]=temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("\n%d",A[i]);
    }
    

    return 0;
}