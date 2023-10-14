#include<stdio.h>

void main()
{
    int a=10,b=20,c;
    printf("\n before executing a:%d and b:%d",a,b);
    c = ++a + a++ + --a + ++b + --b - b--;
    printf("\n c is :%d",c);
}