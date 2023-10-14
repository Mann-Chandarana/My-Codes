#include <iostream>
#include <vector>
using namespace std;
/////////////////////////////////////// find path
void find_Path(vector<vector<int>> arr, int i, int j, string s)
{
    if (i >= arr.size() || j >= arr[0].size())
    {
        return;
    }
    if (i == arr.size() && j == arr[0].size())
    {
        cout << s << endl;
        return;
    }
    s += 'D';
    find_Path(arr, i + 1, j, s);
    s.pop_back();

    s += 'R';
    find_Path(arr, i, j + 1, s);
    s.pop_back();
}
/////////////////////////////////////// find path with four
void find_path_with_four(vector<vector<int>> arr, int i, int j, string s, vector<vector<int>> visited)
{
    if (i >= arr.size() || j >= arr[0].size())
    {
        return;
    }
    if (i == arr.size() && j == arr[0].size())
    {
        cout << s << endl;
        return;
    }
    visited[i][j] = 1;

    s += 'D';
    find_Path(arr, i + 1, j, s);
    s.pop_back();

    s += 'R';
    find_Path(arr, i, j + 1, s);
    s.pop_back();

    s += 'U';
    find_Path(arr, i - 1, j, s);
    s.pop_back();

    s += 'L';
    find_Path(arr, i, j - 1, s);
    s.pop_back();

    visited[i][j] = 0;
}
int main()
{

    return 0;
}