#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 34; 
    int *ptr; // This is a wild pointer
    //*ptr = 34;  This is not good thing to do
    ptr = &a; // ptr is no longer wild pointer
    printf("The value of a is %d",*ptr);

    return 0;
}