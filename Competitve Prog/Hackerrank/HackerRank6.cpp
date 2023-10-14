#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// int main()
// {
//     int n;
//     vector<int> vec1;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int element;
//         cin >> element;
//         vec1.push_back(element);
//     }
//     sort(vec1.begin(), vec1.end());
//     for (int i = 0; i < n; i++)
//     {
//         cout << vec1[i] << " ";
//     }

//     return 0;
// }

// int main()
// {
//     int n, n1, n2, n3;
//     cin >> n;
//     vector<int> v1;
//     int element;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> element;
//         v1.push_back(element);
//     }
//     cin >> n1;
//     cin >> n2 >> n3;
//     v1.erase(v1.begin() + (n1 - 1));
//     v1.erase(v1.begin() + (n2 - 1), v1.begin() + (n3 - 1));
//     cout << v1.size() << endl;
//     for (int i = 0; i < v1.size(); i++)
//     {
//         cout << v1[i] << " ";
//     }

//     return 0;
// }

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int m, num;
   cin >> m;
   vector<int> v;
   for (int i=0; i<m; i++){
       cin >> num;
       v.push_back(num);
   }
   int n, val;
   cin >> n;
   for (int i=0; i<n; i++){
       cin >> val;
       vector<int>::iterator low = lower_bound(v.begin(), v.end(), val);
       if (v[low - v.begin()] == val)
           cout << "Yes " << (low - v.begin()+1) << endl;
       else
           cout << "No " << (low - v.begin()+1) << endl;
   }
   return 0;
}