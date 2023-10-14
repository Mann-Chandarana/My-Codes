#include <stdio.h>

// int main()
// {
//     printf("Hello world\n");
//     int i;
//     for (i =0;i < 5; i++)   
//     {
//         printf("%d",i);
//     }
    
//     return 0;
// }

int main()
{
    printf("Hello world\n");
    int i,j;
    for (i =0,j =0;i < 5,j < 3; i++)   
    {
        printf("%d,%d\n",i,j);
        j++;
    }
    
    return 0;
}
