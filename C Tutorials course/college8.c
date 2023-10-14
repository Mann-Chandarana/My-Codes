#include <stdio.h>

int main()
{
    int num1, num2, num3, Big;
    printf("Enter three numbers\n");
    scanf("%d\n %d\n %d", &num1, &num2, &num3);
    printf("You enterd number %d ,%d and %d", num1, num2, num3);
    Big = (num1 > num2 && num1 > num3) ? num1 : (num2 > num3) ? num2 : num3;
    printf("\nThe Largest number is %d",Big);
    return 0;
}