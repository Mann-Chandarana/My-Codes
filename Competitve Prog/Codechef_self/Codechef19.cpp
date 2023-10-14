#include <iostream>
using namespace std;

char Win(string game)
{
    char winner = game[0];
    for (int i = 0; i < game.length(); i++)
    {
        if ((game[i + 1] != '\0') && ((winner == 'S' && game[i + 1] == 'R') || (winner == 'P' && game[i + 1] == 'S') || (winner == 'R' && game[i + 1] == 'P')))
        {
            winner = game[i + 1];
        }

        else if ((game[i + 1] != '\0') && (winner == game[i + 1]))
        {
            continue;
        }

        else if ((game[i + 1] != '\0') && ((winner == 'S' && game[i + 1] == 'P') || (winner == 'P' && game[i + 1] == 'R') || (winner == 'R' && game[i + 1] == 'S')))
        {
            continue;
        }
    }
    return winner;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        string game;
        cin >> n;
        cin >> game;

        for (int i = 0; i < game.length(); i++)
        {
            cout << Win(game.substr(i, game.length()));
        }
        cout << endl;
    }

    return 0;
}