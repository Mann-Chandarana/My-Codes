#include <stdio.h>

int main()
{
    int Distance, Meter, feet, inches, centimeter;
    printf("Enter the Distance between two cities in KM\n");
    scanf("%d", &Distance);
    printf("You entered %d\n", Distance);
    Meter = Distance * 1000;
    printf("Distance in Meters is %d\n", Meter);
    feet = Distance * 3280;
    printf("Distance in Feets is %d\n", feet);
    inches = Distance * 39370;
    printf("Distance in inches is %d\n", inches);
    centimeter = Distance * 100000;
    printf("Distance in centimeter is %d\n", centimeter);

    return 0;
}