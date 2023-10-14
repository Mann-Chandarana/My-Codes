#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count_a = 0, count_b = 0;
    char maxi;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            count_a++;
        }
        else
        {
            count_b++;
        }
    }

    maxi = count_a > count_b ? 'a' : 'b';
    int count, max_count = INT_MIN;
    bool arr[s.length()] = {false};

    for (int i = 0; i < s.length(); i++)
    {
        int remi = n;
        count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != maxi && remi > 0)
            {
                if (arr[j] == false)
                {
                    arr[j] = true;
                    remi--;
                    count++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            else if (s[j] != maxi && remi <= 0)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        max_count = max(max_count, count);
    }
    cout << max_count << endl;

    return 0;
}