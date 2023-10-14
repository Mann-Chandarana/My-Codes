#include <stdio.h>

void changevalue(int* address)
{
    *address = 345; // value at address
}
int main()
{
    int a=34, b=56;
    printf("The value of a now is %d",a);
    changevalue(&a); 
    printf("\nThe value of a now is %d",a);
    return 0;
}

// Quick quiz
//Given two numbers a and b, add them then subtract them and assign them to a and b using call by reference

// a=-4
// b=3

// after running the funcion value of a and b should be 
// a=7
// b=1