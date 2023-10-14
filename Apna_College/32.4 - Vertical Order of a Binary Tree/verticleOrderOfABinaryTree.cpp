#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int val)
    {
        key = val;
        left = NULL;
        right = NULL;
    }
};

void getVerticalOrder(Node *root, int hDis, map<int, vector<int>> &m) // O(N * logN)
{
    if (root == NULL)
        return;

    m[hDis].push_back(root->key);
    getVerticalOrder(root->left, hDis - 1, m);
    getVerticalOrder(root->right, hDis + 1, m);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> m;
    int hDis = 0;

    getVerticalOrder(root, hDis, m);

    for (auto i : m)
    {
        for (int j = 0; j < i.second.size(); j++)
        {
            cout << i.second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}