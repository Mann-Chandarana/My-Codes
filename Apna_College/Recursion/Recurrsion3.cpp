#include <iostream>
using namespace std;
//////////////////////////////////////// Tilling problem
int tiling_ways(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int hori = tiling_ways(n - 2);  // <- placing tiles horizontally
    int verti = tiling_ways(n - 1); // <- placing tiles bertically
    return (hori + verti);
}
//////////////////////////////////////// Friends Pairing
int friends_Pairing(int n)
{
    if (n <= 2)
    {
        return n;
    }
    return (friends_Pairing(n - 1) + friends_Pairing(n - 2) * (n - 1));
}
//////////////////////////////////////// KnapSnack Problem
int knapsnack(int *arr, int *wt, int n, int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return knapsnack(arr, wt, n - 1, w);
    }

    return max(knapsnack(arr, wt, n - 1, w - wt[n - 1]) + arr[n - 1], knapsnack(arr, wt, n - 1, w));
}
////////////////////////////////////////
int main()
{
    cout << friends_Pairing(4) << endl;
    return 0;
}