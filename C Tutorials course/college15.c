#include <stdio.h>

int main()
{
    char str[50];
    int alpha = 0, digit = 0, special = 0;
    int i;

    printf("Enter the string:\n");
    gets(str);

    puts("\n The string is ....\n");
    puts(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
        {
            alpha++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit++;
        }
        else
        {
            special++;
        }
    }
    printf("Total alphabets are %d :\n",alpha);
    printf("Total digits are %d :\n",digit);
    printf("Total Special symbol are %d :\n",special);

    return 0;
}