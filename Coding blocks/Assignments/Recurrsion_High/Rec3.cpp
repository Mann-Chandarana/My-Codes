////////////// MazePath_D

#include <iostream>
using namespace std;

bool is_safe(int x, int y, int m, int n)
{
    if ((x >= 0 && x < m) && (y >= 0 && y < n))
    {
        return true;
    }
    return false;
}

int count = 0;

void Maze_path(int m, int n, int x, int y, string out)
{
    if (x == m - 1 && y == n - 1)
    {
        count++;
        cout << out << " ";
        return;
    }

    ///// Down

    if (is_safe(x + 1, y, m, n))
    {
        out.push_back('V');
        Maze_path(m, n, x + 1, y, out);
        out.pop_back();
    }

    ///// Right
    if (is_safe(x, y + 1, m, m))
    {
        out.push_back('H');
        Maze_path(m, n, x, y + 1, out);
        out.pop_back();
    }

    ////// Diagnoal
    if (is_safe(x + 1, y + 1, m, n))
    {
        out.push_back('D');
        Maze_path(m, n, x + 1, y + 1, out);
        out.pop_back();
    }
}

int main()
{
    int N1, N2;
    cin >> N1 >> N2;

    string output;
    Maze_path(N1, N2, 0, 0, output);
    cout << endl
         << count;

    return 0;
}