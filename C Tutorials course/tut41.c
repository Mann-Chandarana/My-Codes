#include <stdio.h>

int main()
{
    char string[] = "<h1> this a heading </h1>";
    parser(string);
    return 0;
}
/*

Input:
<h1> this is heading </h1>

Output:
This is a heading

Input:
<span> This is a heading </span>

Output
This is a heading

*/