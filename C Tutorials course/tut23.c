#include <stdio.h>

int main()
{
    int marks[4] = {4, 23, 2, 3};

    for (int i = 0; i < 4; i++)
    {
        printf("Enter the value of %d in an array\n", i);
        scanf("%d", &marks[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("The value of %d element of an array is %d\n", i, marks[i]);
    }
}

    // marks[0] = 34;
    // printf("The marks of student 1 is %d\n",marks[0]);
    // marks[0]=53;
    // marks[1]=51;
    // marks[2]=21;
    // printf("The marks of student 1 is %d\n",marks[0]);
    // return 0;
    //}

    // int main()
    // {
    //     int marks[2][4] = {{4, 23, 2, 3},
    //                        {5, 26, 58, 37}};

    //     for (int i = 0; i < 2; i++)
    //     {
    //         for (int j = 0; j < 4; j++)
    //         {
    //             printf("The value of %d,%d element of the array is%d\n", i, j, marks[i][j]);
    //         }
    //     }
    // }