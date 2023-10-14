#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "harry";
    char s2[] = "ravi";
    char s3[54];
    printf("The strcmp for s1, s2 returned %d\n", strcmp(s1, s2));
    puts(strcat(s1, s2));
    printf("The length of s1 is %d", strlen(s1));
    printf("\nThe length of s2 is %d", strlen(s2));
    printf("\nThe reverse of s1 is:");
    puts(strrev(s1));
    strcpy(s3, strcat(s1, s2));
    puts(s3);

    return 0;
}