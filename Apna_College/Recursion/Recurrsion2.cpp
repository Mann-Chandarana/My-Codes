////////////////////////////////////// Question - 1

#include <iostream>
using namespace std;

int count_Path(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += count_Path(s + i, e);
    }
    return count;
}
//////////// Apna college Solution
int countPathMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1);
}
//////////// Solution by me
void count_path_maze(int n, int i, int j, int &count)
{
    if (i == n - 1 && j == n - 1)
    {
        count++;
        return;
    }
    if (i >= n || j >= n)
    {
        return;
    }
    count_path_maze(n, i + 1, j, count);
    count_path_maze(n, i, j + 1, count);
}
int main()
{
    int count = 0;
    count_path_maze(3, 0, 0, count);
    cout << count << endl;
    return 0;
}