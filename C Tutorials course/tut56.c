#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaterandomnumber(int n)
{
    srand(time(NULL)); // srand takes seed as an input and is defined inside stdlib.h
    return rand() % n;
}

int greater(char char1, char char2)
{
    // For Rock, paper and scissors - return 1 if c1>c2 and 0 otherwise. If c1==c2 it will return -1
    if (char1 == char2)
    {
        return -1;
    }
    if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else  if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }

    if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dic[] = {'r', 'p', 's'};
    printf("Welcome to rock,paper and scissors.\n");
    for (int i = 0; i < 3; i++)
    {
        // Take player 1's input
        printf("Player 1's Turn:\n");
        printf("Choose 1 for rock,2 for paper and 3 for scissors.\n");
        scanf("%d", &temp);
        getchar();
        playerChar = dic[temp - 1];
        printf("You choose %c\n\n", playerChar);

        // Generate computer's input
        printf("Computer's Turn:\n");
        printf("Choose 1 for rock,2 for paper and 3 for scissors.\n");
        temp = generaterandomnumber(3) + 1;
        compChar = dic[temp - 1];
        printf("Computer choose %c\n\n", compChar);

        // Compare the score

        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
            printf("CPU got it!\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
            printf("It's a draw\n");
        }
        else
        {
            playerScore += 1;
            printf("You got it!\n");
        }
        if (playerScore > compScore)
        {
            printf("You Win the game\n");
        }
        else if (playerScore < compScore)
        {
            printf("CPU Win the game\n");
        }
        else
        {
            printf("Game is Draw\n");
        }
        printf("You %d\n",playerScore);
        printf("CPU %d\n",compScore);
    }
    return 0;
}