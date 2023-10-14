#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int *marks, int number_of_students, char gender)
{
    int sum = 0;
    for (int i = (gender == 'b' ? 0 : 1); i < number_of_students; i = i + 2)
    {
        sum += *(marks + i);
    }
    return sum;
}

int main()
{
    int n, sum;
    char gender;
    scanf("%d", &n);
    int *marks = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", (marks + i));
    }
    scanf("%c", &gender);
    sum = marks_summation(marks, n, gender);
    printf("%d", sum);

    return 0;
}