#include <stdio.h>

int main()
{
    printf("Lets learn about pointers\n");
    int a=75;
    int* ptra = &a;
    int*ptr2 = NULL;
    printf("The addres of pointer to a is %p\n",&ptra);
    printf("The addres of a is %p\n",&a);
    printf("The value of a is %d\n",a);
    printf("The value of a is %d\n",*ptra);
    printf("The addres of some garbage  is %p\n",ptr2);
    return 0;
}
