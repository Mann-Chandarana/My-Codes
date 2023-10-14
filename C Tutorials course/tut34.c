#include <stdio.h>
void printstr(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
}
int main()
{
    // char str[] = {'M', 'A', 'N', 'N', '\0'};
    // char str[6] = "harry";
    char str[34];
    gets(str);
    printf("Using custom function printsr\n");
    printf("Using printf %s\n",str);
    printf("Using puts: \n");
    puts(str);
    //printstr(str);

    return 0;
}