#include <stdio.h> 

int main()
{
    // char a = '3';
    // char*ptra = &a;
    // printf("%d\n",ptra);
    // ptra++;
    // printf("%d\n",ptra);
    // printf("%d",ptra+1);
    int arr[]={1,2,3,4,5,6,7};
    printf("Value at position 3 of the array is %d\n",arr[3]);

    printf("The address of the first element of the array is %d\n", &arr[0]);
    printf("The address of the first element of the array is %d\n", arr);
    printf("The address of the second element of the array is %d\n", &arr[1]);
    printf("The address of the second element of the array is %d\n", arr + 1);
    // arr-- // this line will throw an error

    printf("The value of the first element of the array is %d\n", *(&arr[0]));
    printf("The value of the first element of the array is %d\n", *(arr));
    printf("The value of the second element of the array is %d\n", *(&arr[1]));
    printf("The value of the second element of the array is %d\n", *(arr + 1));

     return 0;
}