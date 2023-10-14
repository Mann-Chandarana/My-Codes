#include <stdio.h>

int isPallidrome(int num)
{
    int reversed = 0;
    int originalnumber = num;
    // Lets reverse the number
    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    printf("The reversed number is %d\n", reversed);
    if (originalnumber == reversed)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 1;
}
int main()
{
    int number;
    printf("Enter your number\n");
    scanf("%d", &number);
    if (isPallidrome(number))
    {
        printf("The number is Pallidrome\n");
    }
    else
    {
        printf("Number is not Pallidrome\n");
    }

    return 0;
}