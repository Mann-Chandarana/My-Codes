#include <stdio.h>
#include <math.h>

float ar(float x, float y, float z);

int main()
{
    float area, a, b, c;
    printf("Enter the sides of the triangle\n");
    scanf("%f\n%f\n%f", &a, &b, &c);
    if (a + b > c && b + c > a && c + a > b)
    {
        area = ar(a, b, c);
        printf("\nThe area of triangle is %f", area);
    }
    else
    {
        printf("\nInvalid triangle");
    }

    return 0;
}
float ar(float x, float y, float z)
{
    float area;
    float S = (x + y + z) / 2;
    area = sqrt(S * (S - x) * (S - y) * (S - z));
    return (area);
}