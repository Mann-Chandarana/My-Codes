#include <stdio.h>
/////////         With argument and with return value
// int sum(int a, int b)
// {
//     return a + b;
// }

// int main()
// {
//     int a, b, c;
//     a = 9;
//     b = 97;
//     c = sum(a, b);
//     printf("The sum is %d \n", c);

//     return 0;
// }

// With argument and without return value
void printstar(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%c", '*');
    }
}

int main()
{

    printstar(7);

    return 0;
}

// Without argument and with return value
// int takenumber()
// {
//     int i;
//     printf("Enter a number\n");
//     scanf("%d", &i);
//     return i;
// }

// int main()
// {
//     int c;
//     c = takenumber();
//     printf("The number entered is %d\n", c);
//     return 0;
}