#include <stdio.h>
int main()
{
    int days,Days,weeks,years;
    printf("Enter Days\n");
    scanf("\n%d",&days);

    years = days/365;
    printf("\nYears:%d",years);
    weeks = (days%365)/7;
    printf("\nWeeks:%d",weeks);
    Days = (days%365)%7;
    printf("\nDays:%d\n",Days);


     return 0;
}