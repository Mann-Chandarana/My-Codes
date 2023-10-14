#include <stdio.h>

// Break
// int main()
// {
//     printf("Hello world\n");
//     int i,age;
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d\nEnter your age\n",i);
//         scanf("%d",&age);
//         if (age>10)
//         {
//             break;
//         }
        
//     }
    
//     return 0;
// }

// Continue
int main()
{
    printf("Hello world\n");
    int i,age;
    for ( i = 0; i < 10; i++)
    {
        printf("%d\nEnter your age\n",i);
        scanf("%d",&age);
        if (age>10)
        {
            continue;
        }
        printf("We have not come across any continue statements");
        
    }
    
    return 0;
}
