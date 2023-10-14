#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    printf("\nEnter Five numbers\n");
    scanf("\n%d",&a);
    scanf("\n%d",&b);
    scanf("\n%d",&c);
    scanf("\n%d",&d);
    scanf("\n%d",&e);

    if (a>b && a>c && a>d && a>e )  
    {
        printf("%d is maximum",a);
    }
    else if (b>c && b>c && b>e)
    {
        printf("%d is maximum",b);
    }
    else if (c>d && c>e)
    {
        printf("%d is maximum",c);
    }
    else if (d>e)
    {
        printf("%d is maximum",d);
    }
    else
    {
        printf("%d is maximum",e);
    }
    return 0;
    

}