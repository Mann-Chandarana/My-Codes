#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int k = 0; k < n; k++)
        {
            vector<int> ar(k + 1);
            for (int l = 0; l <= k; l++)
            {
                cin >> ar[l];
            }
            arr.push_back(ar);
        }
        for (int k = n - 1; k > 0; k--)
        {
            for (int m = 0; m < arr[k - 1].size(); m++)
            {
                arr[k - 1][m] += max(arr[k][m], arr[k][m + 1]);
            }
        }
        cout << arr[0][0] << endl;
    }

    return 0;
}

// #include <iostream>
// using namespace std;
// #include<math.h>
// int main() {
// 	// your code goes here
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{

// 	    int n;
// 	    cin>>n;
// 	    int a[n][n];
// 	    for(int i=0;i<n;i++)
// 	    {for(int j=0;j<i+1;j++)
// 	    {cin>>a[i][j];}
// 	    }
// 	    for(int i=n-2;i>=0;i--)
//            {
//                for(int j=0;j<=i;j++)
//                {
//                    if((a[i][j]+a[i+1][j])>(a[i][j]+a[i+1][j+1]))
//                    {
//                         a[i][j]=a[i][j]+a[i+1][j];
//                    }
//                    else
//                     a[i][j]=a[i][j]+a[i+1][j+1];

//                }
//            }
//            cout<<a[0][0]<<endl;
// 	}
// 	return 0;
// }
