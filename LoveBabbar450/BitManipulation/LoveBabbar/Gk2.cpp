/* https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1 */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

vector<int> singleNumber(vector<int> nums)
{
    int xorr = 0;

    for (auto &element : nums)
        xorr ^= element;

    int last_set_bit = xorr & -xorr;

    int xor0 = 0, xor1 = 0;

    for (auto &element : nums)
    {
        if (element & last_set_bit)
            xor0 ^= element;

        else
            xor1 ^= element;
    }

    vector<int> answer = {xor0, xor1};

    sort(all(answer));

    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 4};
    singleNumber(nums);
    return 0;
}