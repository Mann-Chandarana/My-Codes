#include <iostream>
#include <vector>
using namespace std;

int squareRoot(int n,int &start,int &end)
{
    int mid,ans = -1;
    while(start < end)
    {
        mid = start + (end - start)/2;
        
        if(mid*mid == n)
            return mid;
        
        if(mid*mid < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid;
    }
    
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int start =0, end = n;
    cout << squareRoot(n,start,end) << endl;

    cout << "Main end.." << endl;
    return 0;
}
