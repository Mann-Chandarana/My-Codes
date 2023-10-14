// Two numbers are entered through the keyboard. Write a program to find the value of one number raised to the power of another.
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter number 1\n");
    scanf("%d", &num1);
    printf("Enter number 2\n");
    scanf("%d", &num2);

    
    int Power=1;
    int i=1;
    while (i <= num2)
    {
        Power = Power* num1;
        i++;
    }
    printf("The value is %d",Power);

    return 0;
}