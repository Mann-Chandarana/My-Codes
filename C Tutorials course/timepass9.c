#include <stdio.h>

int main()
{
    int SizeA;
    int SizeB, SizeC;
    printf("Enter Size of array A\n");
    scanf("%d", &SizeA);
    getchar();
    printf("Enter Size of array B\n");
    scanf("%d", &SizeB);

    SizeC = SizeA + SizeB;
    int arrayA[SizeA], arrayB[SizeB], arrayC[SizeC];
    printf("Enter first ArrayA\n");
    for (int i = 0; i < SizeA; i++) /////////
    {
        scanf("%d\n", &arrayA[i]);
    }
    printf("Enter first ArrayB\n");
    for (int j = 0; j < SizeB; j++) /////////
    {
        scanf("%d\n", &arrayB[j]);
    }

    int l = 0;

    for (int k = 0; k < SizeC; k++)
    {
        if (k > (SizeA - 1))
        {
            arrayC[k] = arrayB[l];
            l++;
        }
        arrayC[k] = arrayA[k];
    }

    printf("The array c is\n");
    for (int m = 0; m < SizeC; m++)
    {
        printf("%d\n", arrayC[m]);
    }

    return 0;
}