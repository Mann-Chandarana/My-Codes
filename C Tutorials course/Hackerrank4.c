// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
//     char num[1000];
//     scanf("%s", &num);
//     for (int i = 0; i < strlen(num) && num[i] != '\0'; i++)
//     {
//         if (num[i] == 48)
//         {
//             zero++;
//         }
//         if (num[i] == 49)
//         {
//             one++;
//         }
//         if (num[i] == 50)
//         {
//             two++;
//         }
//         if (num[i] == 51)
//         {
//             three++;
//         }
//         if (num[i] == 52)
//         {
//             four++;
//         }
//         if (num[i] == 53)
//         {
//             five++;
//         }
//         if (num[i] == 54)
//         {
//             six++;
//         }
//         if (num[i] == 55)
//         {
//             seven++;
//         }
//         if (num[i] == 56)
//         {
//             eight++;
//         }
//         if (num[i] == 57)
//         {
//             nine++;
//         }
//     }
//     printf("%d %d %d %d %d %d %d %d %d %d", zero, one, two, three, four, five, six, seven, eight, nine);

//     return 0;
// }
#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001], i;
    int f, j;
    scanf("%s", s);
    for (i = 48; i < 58; i++)
    {
        f = 0;
        for (j = 0; j < strlen(s); j++)
        {
            if (s[j] == i)
            {
                f++;
            }
        }
        printf("%d ", f);
    }
    return 0;
}