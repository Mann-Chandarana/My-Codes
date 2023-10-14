#include <stdio.h>
#include <string.h>
struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
};

int main()
{
    struct Student harry, ravi, Shubham;
    harry.id = 1;
    ravi.id = 2;
    Shubham.id = 3;
    harry.marks = 66;
    ravi.marks = 466;
    Shubham.marks = 566;
    harry.fav_char = 'p';
    ravi.fav_char = 'p';
    Shubham.fav_char = 'p';
    strcpy(harry.name, "Harry poter");
    printf("Harry got %d marks\n", harry.marks);
    printf("Harry's name is:%s\n", harry.name);

    return 0;
}