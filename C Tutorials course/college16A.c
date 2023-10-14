#include <stdio.h>
#include <string.h>

void check(char[], int);

int main()
{
    char word[15];
    printf("Enter the word to check if it is a palidrome :\n");
    gets(word);
    check(word, 0);

    return 0;
}
void check(char word[], int index)
{
    int len = strlen(word) - (index + 1);

    if (word[index] == word[len])
    {
        if (index + 1 == len || index == len)
        {
            printf("The Entered Word is a Palindrome.\n");
            return;
        }
        check(word, index + 1);
    }
    else
    {
        printf("The Entered Word is not a Palindrome.\n");
    }
}