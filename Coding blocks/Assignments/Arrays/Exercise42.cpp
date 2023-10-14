////////////////////// Finding CB numbers

#include <iostream>
using namespace std;

bool check_CB(string s)
{
    if (stoll(s) == 0 || stoi(s) == 1)
    {
        return false;
    }

    int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; i++)
    {
        if (stoll(s) == arr[i])
        {
            return true;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (stoll(s) % arr[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    bool arr[100] = {false};
    bool error = false;

    for (int len = 1; len < s.size(); len++)
    {
        for (int pos = 0; pos < s.size() - len + 1; pos++)
        {
            if (check_CB(s.substr(pos, len)))
            {
                error = false;

                for (int i = pos; i < pos + len; i++)
                {
                    if (arr[i] == true)
                    {
                        error = true;
                        break;
                    }
                }
                if (error == false)
                {
                    for (int i = pos; i < pos + len; i++)
                    {
                        arr[i] = true;
                    }

                    count++;
                    cout << s.substr(pos, len) << endl;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}