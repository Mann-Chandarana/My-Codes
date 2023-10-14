#include <stdio.h>

int main()
{
    int num1,num2,num3,num4,largest;
    printf("Enter five numbers\n");
    scanf("\n%d \n%d \n%d \n%d",&num1,&num2,&num3,&num4);
    largest = (num1>num2 && num1>num3 && num1>num4 ? num1:(num2>num3 && num2>num4 ? num2:(num3>num4 ?num3:num4)));
    printf("The largest is %d",largest);
    
     return 0;
}