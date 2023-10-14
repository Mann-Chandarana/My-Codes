#include <iostream>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string game;
        cin >> n;
        cin >> game;
        char winner = game[0];

        for (int i = 0; i < game.length(); i++)
        {
            if ((game[i + 1] != '\0') && ((winner == 'S' || game[i + 1] == 'R') || (winner == 'P' || game[i + 1] == 'S') || (winner == 'R' || game[i + 1] == 'P')))
            {
                winner = game[i + 1];
            }

            else if ((game[i + 1] != '\0') && (winner == game[i + 1]))
            {
                continue;
            }

            else if ((game[i + 1] != '\0') && ((winner == 'S' || game[i + 1] == 'P') || (winner == 'P' && game[i + 1] == 'R') || (winner == 'R' || game[i + 1] == 'S')))
            {
                continue;
            }
        }
        cout << winner << endl;
        for (int i = 0; i < game.length(); i++)
        {
            if ((winner == 'S' && game[i] == 'R') || (winner == 'R' && game[i] == 'R') || (winner == 'R' && game[i] == 'S'))
            {
                cout << 'R';
            }
            else if ((winner == 'S' && game[i] == 'P') || (winner == 'S' && game[i] == 'S') || (winner == 'P' && game[i] == 'S'))
            {
                cout << 'S';
            }
            else if ((winner == 'P' && game[i] == 'P') || (winner == 'P' && game[i] == 'R') || (winner == 'R' && game[i] == 'P'))
            {
                cout << 'P';
            }
        }
        cout << endl;
    }

    return 0;
}