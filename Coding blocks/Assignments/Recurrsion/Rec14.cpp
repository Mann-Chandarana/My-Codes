/////////// Tower of hanoi

#include <iostream>
using namespace std;

int count = 0;

void TowerOfHanoi(int n, string src, string des, string helper)
{
    if (n == 0)
    {
        return;
    }

    TowerOfHanoi(n - 1, src, helper, des);
    cout << "Move " << n << "th disc from " << src << " to " << des << endl;
    count++;
    TowerOfHanoi(n - 1, helper, des, src);
}

int main()
{
    int n;
    cin >> n;
    TowerOfHanoi(n, "T1", "T2", "T3");
    cout << count << endl;
    return 0;
}