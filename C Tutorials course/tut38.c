#include <stdio.h>

// typedef struct Student
// {
//     int id;
//     int marks;
//     char fav_char;
//     char name[34];
//  } std;
int main()
{
    // int*a, b; here a will be pointer and b will be integer
    typedef int* intPointer;
    intPointer a,b;
    int c =89;
    a=&c;
    b=&c;

    // std s1, s2;
    // s1.id = 56;
    // s2.id = 89;
    // printf("The value of s1's id is %d\n", s1.id);
    // typedef <previous_name> <alias_name>;
    // typedef unsigned long u1;
    // typedef int integer;
    // u1 l1, l2, l3;
    // integer a = 4;
    // printf("The value of a is %d", a);
    // return 0;
}