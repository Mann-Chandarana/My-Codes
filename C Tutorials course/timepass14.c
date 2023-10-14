#include <stdio.h>
#define PI 3.14

int main()
{
    int area, choice, l, b, B, h;
    float r,Area;
    printf("Press\n1) For area of rectangle\n2) For area of circle\n3) For area of triangle\n4) Exit()\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter length and breadth\n");
        scanf("%d\n%d", &l, &b);
        area = l * b;
        printf("Area of Rectangle is %d\n", area);
        break;

    case 2:
        printf("Enter radius of a circle\n");
        scanf("%f", &r);
        Area = PI * r * r;
        printf("The area of circle is %f\n", Area);
        break;

    case 3:
        printf("Enter Height and Base of a triangle\n");
        scanf("%d\n%d", &B, &h);
        area = 0.5 * B * h;
        printf("The area of triangle is %d\n", area);
        break;

    case 4:
        printf("Exiting the program");
        return 0;
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");
    return 0;
}