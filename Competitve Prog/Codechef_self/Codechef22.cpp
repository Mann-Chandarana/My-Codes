#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int No_of_players, Height;
        cin >> No_of_players >> Height;

        int *arr = new int[No_of_players];

        for (int i = 0; i < No_of_players; i++)
        {
            cin >> arr[i];
        }

        int shot_player = 0;

        for (int i = 0; i < No_of_players; i++)
        {
            if (arr[i] > Height)
            {
                shot_player++;
            }
        }

        cout << shot_player << endl;
    }

    return 0;
}