#include <stdio.h>
#include <string.h>
int main()
{
    int n,fact=1;
    printf("Enter the number for which you want factorial\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        fact=fact*i;
    }
    printf("The Factorial of the number %d is %d",n,fact);
    
    return 0;
}