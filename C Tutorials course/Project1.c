#include <stdio.h>

int main()
{
    int n, temp, min1, min2, min, ans;
    printf("Enter the number of rows you want\n");
    scanf("%d", &n);
    temp = 2 * n - 1;
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            min1 = i < temp - i ? i : temp - i - 1;
            min2 = j < temp - j ? j : temp - j - 1;
            min = min1 < min2 ? min1 : min2;
            ans = n - min;
            printf("%d", ans);
        }
        printf("\n");
    }

    return 0;
}
// or
// int main() 
// {

//     int n;
//     scanf("%d", &n);
//     int temp = n*2 - 1;
//     for(int i=0;i<temp;i++){
//         for(int j=0;j<temp;j++){
//             int min = i < j ? i : j;
//             min = min < temp-i ? min : temp-i-1;
//             min = min < temp-j-1 ? min : temp-j-1;
//             printf("%d ", n-min);
//         }
//         printf("\n");
//     }
//     return 0;
// }