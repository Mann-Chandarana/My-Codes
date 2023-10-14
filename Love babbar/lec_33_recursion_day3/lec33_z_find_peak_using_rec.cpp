#include <iostream>
#include <vector>
using namespace std;

int returnPeak(vector<int> &arr,int &start,int &end)
{
    if(start >= end)
        return start;
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] < arr[mid + 1])
    {
        start = mid + 1;
        return returnPeak(arr,start,end);
    }
    else
    {
        end = mid;
        return returnPeak(arr,start,end);
    }
}

int main()
{
    vector<int> arr = {1,6,7,8,9,5,4,3,1};
    int start = 0, end = arr.size() - 1;
    
    cout << returnPeak(arr,start,end) << endl;

    cout << "Main end.." << endl;
    return 0;
}
