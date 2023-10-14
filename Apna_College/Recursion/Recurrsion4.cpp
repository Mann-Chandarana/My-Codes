#include <iostream>
using namespace std;
//////////////////////////////// Rat in maze problem
bool isSafe(int **arr, int x, int y, int n)
{
    if (x <= n && y <= n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}
////////////////////////////////
bool rat_in_maze(int **arr, int x, int y, int n, int **&sol)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        if (rat_in_maze(arr, x + 1, y, n, sol))
        {
            return true;
        }
        if (rat_in_maze(arr, x, y + 1, n, sol))
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}
////////////////////////////////

int main()
{

    return 0;
}