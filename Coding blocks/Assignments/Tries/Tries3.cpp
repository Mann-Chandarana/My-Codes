//////////////// Maximum pair of xor and maximum XOR in a subarray

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *zero; //// For zero
    Node *one;  //// For one
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->zero == NULL)
                {
                    temp->zero = new Node();
                }
                temp = temp->zero;
            }
            else
            {
                if (temp->one == NULL)
                {
                    temp->one = new Node();
                }
                temp = temp->one;
            }
        }
    }

    int max_xor_helper(int num)
    {
        Node *temp = root;
        int current_ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (bit == 0)
            {
                if (temp->one != NULL)
                {
                    temp = temp->one;
                    current_ans += (1 << i);
                }
                else
                {
                    temp = temp->zero;
                }
            }
            else
            {
                if (temp->zero != NULL)
                {
                    temp = temp->zero;
                    current_ans += (1 << i);
                }
                else
                {
                    temp = temp->one;
                }
            }
        }
        return current_ans;
    }

    int max_xor(int *input, int n)
    {
        int max_xo = 0;

        for (int i = 0; i < n; i++)
        {
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            max_xo = max(current_xor, max_xo);
        }
        return max_xo;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    int *input = new int[n];
    int xorSoFar = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        input[i] = input[i] ^ xorSoFar;
        cout << input[i] << " ";
    }
    cout << endl;

    cout << t.max_xor(input, 4) << endl;
    delete[] input;

    return 0;
}
