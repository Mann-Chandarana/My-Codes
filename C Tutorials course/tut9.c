#include <stdio.h>
#define PI = 3.14
/* this is multiline comment

ignored by my complier
*/


int main()
{
    int a =8;
    const float b = 7.333;
    // PI = 7.34;                   // cannot do this since PI is constant
    // b = 7.222;                   // cannot do this since b is constant
    // printf("Hello world\n");
    printf("tab charcter \t\t my blackslash \a, my blackslash \n");
    //printf("The value of a is %d and the value of b is %0.4f\n",a , b);
    // printf("%8.4f\n",b);
    return 0;
}
