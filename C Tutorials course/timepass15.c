#include <stdio.h>

int main()
{
    printf("Created by Mann Chandarana,Rollno 20TCS071\n");
    int player1, player2;
    char r, R, p, P, s, S;
    printf("Choose\n1) r or R for rock\n2) p or P for paper\n3) s or S for paper\n");
    printf("Player 1 turn\n");
    player1 = getchar();
    printf("Player 1 has choosen %c\n", player1);
    getchar();
    printf("Choose\n1) r or R for rock\n2) p or P for paper\n3) s or S for paper\n");
    printf("Player 2 turn\n");
    player2 = getchar();
    printf("Player 2 has choosen %c\n", player2);
    
    if (player1 == 'p' && player2 == 's' || player1 == 'P' && player2 == 'S')
    {
        printf("Player 2  wins\n");
    }
    else if (player1 == 's' && player2 == 'r' || player1 == 's' && player2 == 'R')
    {
        printf("Player 2  wins\n");
    }
    else if (player1 == 'r' && player2 == 'p' || player1 == 'R' && player2 == 'P')
    {
        printf("Player 2  wins\n");
    }
    
    else if (player1 == 'r' && player2 == 'r' || player1 == 'R' && player2 == 'R' || player1 == 's' && player2 == 's' 
            || player1 == 'S' && player2 == 'S' ||player1 == 'p' && player2 == 'p' || player1 == 'P' && player2 == 'P')
    {
        printf("Nobody wins\n");
    }
    else
    {
        printf("Player1 wins\n");
    }
    printf("\nCreated by Mann Chandarana and Roll no is 20TCS071\n");
    return 0;
}