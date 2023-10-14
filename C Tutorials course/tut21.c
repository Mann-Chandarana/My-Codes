#include <stdio.h>

int factorial(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    int num;
    printf("Enter the number you want factorial\n");
    scanf("%d", &num);
    printf("The factorial of the entered number %d is %d", num, factorial(num));
    return 0;
}
