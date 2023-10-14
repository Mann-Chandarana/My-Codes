// Suppose ABC is a private limited company which manages the employee records of other companies. Employee id can be of any length, and it can contain any character. The following are the task you have to perform for three employees.

// Take the length of an employee id as an input and store it in an integer length variable
// Take an employee id as an input and display it on the screen.
// Save the employee id in a character array, which is allocated dynamically.
// Create only one character array dynamically.

#include <stdio.h>
#include <stdlib.h>

int main()
{
     int chars, i = 0;
     char a,b;
     char *ptr;
     while (i < 3)
     {
          printf("Employee No %d:Enter the number of character in your employee Id\n", i + 1);
          scanf("%d", &chars);
          getchar();   // very important
          printf("Enter the value of a\n");
          scanf("%c",&a);
          getchar();     // very important
          printf("Enter the value of b\n");
          scanf("%c",&b);
          ptr = (char *)malloc((chars + 1) * sizeof(char));
          printf("Enter Employee ID\n");
          scanf("%s", ptr);
          printf("Your Employee ID is %s\n", ptr);
          free(ptr);
          i = i + 1;
     }

     return 0;
}
