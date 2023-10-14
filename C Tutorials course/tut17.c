#include <stdio.h>

// int main()
// {
//     label:
//          printf("We are inside label");
//          goto end;
//     printf("Hello world\n");
//     goto label;

//     end:
//         printf("We are at end now");
//     return 0;
// }

#include <stdio.h>

int main()
{
    int i,j,num;
    for ( i = 0; i < 8; i++)
    {
         printf("%d\n",i);
         for ( j = 0; j < 8; j++)
         {
             printf("Enter your number,enter 0 to exit\n");
             scanf("%d",&num);
             if (num==0)
             {
                 goto end;
             }
             
         }
         
    }
    end:
    return 0;
}

